#include <iostream>
#include <string.h>
using namespace std;
//편의를 위해서 우, 하, 좌, 상 순서로

int dx[4] = { 1, 0, -1, 0 };
int dy[4] = { 0, 1, 0, -1 };

int main()
{
	int t, temp;
	scanf("%d", &t);
	temp = t;
	int n;
	int matrix[11][11];
	int i, j;
	int dindex;
	int k;
	int l;
	int ny, nx;
	while (t--)
	{
		scanf("%d", &n);
		k = 1;
		memset(matrix, 0, sizeof(matrix));
		i = 1, j = 1;
		dindex = 0;
		while (k <= n * n)
		{
			matrix[i][j] = k;
			
			for (l = 0; l < 4; l++)
			{
				ny = i + dy[dindex];
				nx = j + dx[dindex];
				if (ny <= 0 || nx <= 0 || nx > n || ny > n)
				{
					dindex++;
					if (dindex == 4)
						dindex = 0;
					continue;
				}
				if (matrix[ny][nx] == 0)
				{
					i = ny;
					j = nx;
					break;
				}
				dindex++;
				if (dindex == 4)
					dindex = 0;
			}
			k++;
		}
		printf("#%d\n", temp - t);
		for (i = 1; i <= n; i++)
		{
			for (j = 1; j <= n; j++)
				printf("%d ", matrix[i][j]);
			printf("\n");
		}
	}
	return 0;
}