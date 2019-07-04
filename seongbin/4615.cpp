#include <iostream>
using namespace std;

int dx[8] = { 0, 1, 1, 1, 0, -1, -1, -1 };
int dy[8] = { -1, -1, 0, 1, 1, 1, 0, -1 };
//dx, dy는 8방향. 상, 우상, 우, 우하, 하, 좌하, 좌, 좌상 순서

int main()
{
   int t;
   int n, m;
   scanf("%d", &t);
   int matrix[9][9] = { 0 };
   int i;
   int x, y, k;
   int dindex = 0;
   int nx, ny;
   int black, white;
   int temp = t;
   while (t--)
   {
      black = 0, white = 0;
      scanf("%d %d", &n, &m);
      matrix[n / 2][n / 2] = 2;
      matrix[n / 2][n / 2 + 1] = 1;
      matrix[n / 2 + 1][n / 2] = 1;
      matrix[n / 2 + 1][n / 2 + 1] = 2;
      for (i = 0; i < m; i++)
      {
         scanf("%d %d %d", &x, &y, &k);
         matrix[y][x] = k;
         for (dindex = 0; dindex < 8; dindex++)
         {
            nx = x + dx[dindex];
            ny = y + dy[dindex];
            while (nx >= 1 && ny >= 1 && nx <= n && ny <= n && matrix[ny][nx] != k && matrix[ny][nx]!=0 )
            {
               nx += dx[dindex];
               ny += dy[dindex];
            }
            if (nx < 1 || ny < 1 || nx > n || ny > n || matrix[ny][nx] == 0)
               continue;
            while (nx != x || ny != y)
            {
               nx -= dx[dindex];
               ny -= dy[dindex];
               matrix[ny][nx] = k;
            }
         }
      }

      for (i = 1; i <= n; i++)
      {
         for (int j = 1; j <= n; j++)
         {
            if (matrix[i][j] == 1)
               black++;
            else if(matrix[i][j] == 2)
               white++;
            matrix[i][j] = 0;
         }
      }
      printf("#%d %d %d\n", temp - t, black, white);
   }
   return 0;
}