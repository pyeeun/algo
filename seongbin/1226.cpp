#include <iostream>
#include <queue>
#include <string.h>

using namespace std;

queue<int> qx;
queue<int> qy;

int dx[4] = { 0, 0, -1, 1 };
int dy[4] = { -1, 1, 0, 0 };

int main()
{
	int t;
	int matrix[16][16];
	int answer;
	int i, j;
	int startx, starty;
	int visited[16][16];
	int nowx, nowy;
	int dindex;

	for (t = 1; t <= 10; t++)
	{
		scanf("%d", &t);
		memset(visited, 0, sizeof(visited));
		answer = 0;
		
		for (i = 0; i < 16; i++)
		{
			for (j = 0; j < 16; j++)
			{
				scanf("%1d", &(matrix[i][j]));
				if (matrix[i][j] == 2)
				{
					starty = i;
					startx = j;
				}
			}
		}
		
		qx.push(startx);
		qy.push(starty);

		while (!qx.empty())
		{
			for (dindex = 0; dindex < 4; dindex++)
			{
				nowx = qx.front() + dx[dindex];
				nowy = qy.front() + dy[dindex];
				if (nowx >= 0 && nowx < 16 && nowy >= 0 && nowy < 16)
				{
					if (matrix[nowy][nowx] == 0 && visited[nowy][nowx] == 0)
					{
						qx.push(nowx);
						qy.push(nowy);
						visited[nowy][nowx] = 1;
					}
					else if (matrix[nowy][nowx] == 3)
					{
						answer = 1;
						break;
					}
				}
			}
			qx.pop();
			qy.pop();
			if (answer == 1)
				break;
		}

		printf("#%d %d\n", t, answer);

		while (!qx.empty())
		{
			qx.pop();
			qy.pop();
		}
	}

	return 0;
}