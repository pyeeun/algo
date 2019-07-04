#include <iostream>
#include <algorithm>
#include <string.h>
using namespace std;

int main()
{
   int t, n, m;
   scanf("%d", &t);
   int temp = t;
   int i, j, k;
   char x;
   int white[51] = { 0 };
   int blue[51] = { 0 };
   int red[51] = { 0 };
   int num;
   int answer;
   while (t--)
   {
      num = 0;
      answer = 2501;
      scanf("%d %d", &n, &m);

      for (i = 1; i <= n; i++)
      {
         for (j = 1; j <= m; j++)
         {
            scanf("%c", &x);
            if (x == 'W')
               white[i]++;
            else if (x == 'B')
               blue[i]++;
            else if (x == 'R')
               red[i]++;
            else if (x == '\n')
               j--;
         }
      }

      for (i = 1; i < n - 1; i++)
      {
         for (j = n; j > i + 1; j--)
         {
            num = 0;
            for (k = 1; k <= n; k++)
            {
               if (k <= i)
                  num += white[k];
               else if (k >= j)
                  num += red[k];
               else
                  num += blue[k];
            }
            answer = min(answer, n*m - num);
         }
      }

      printf("#%d %d\n", temp - t, answer);
      memset(white, 0, sizeof(white));
      memset(blue, 0, sizeof(blue));
      memset(red, 0, sizeof(red));
   }
   return 0;
}