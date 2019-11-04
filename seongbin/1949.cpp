#include <iostream>
#include <algorithm>
#include <queue>
using namespace std;

typedef struct _where
{
	int x;
	int y;
}_where;

int n, k;
int matrix[8][8];
int answer;
int max_num;
int dx[4] = { 0, 0, -1, 1 };
int dy[4] = { -1, 1, 0, 0 };
queue<int> qx;
queue<int> qy;
queue<int> depth;

void solve()
{
	int x, y;
	int dindex;
	while (!qx.empty())
	{
		for (dindex = 0; dindex < 4; dindex++)
		{
			x = qx.front() + dx[dindex];
			y = qy.front() + dy[dindex];
		
			if (x >= 0 && y >= 0 && x < n && y < n)
			{
				if (matrix[y][x] < matrix[y - dy[dindex]][x - dx[dindex]])
				{
					qx.push(x);
					qy.push(y);
					depth.push(depth.front() + 1);
				}
			}
		}
		qx.pop();
		qy.pop();
		answer = max(answer, depth.front());
		depth.pop();
	}
}

int main()
{
	int t, temp;
	int i, j;
	int top_index;
	int tempk;
	int tempmat;
	_where top[5];
	scanf("%d", &t);
	temp = t;

	while (t--)
	{
		scanf("%d %d", &n, &k);
		max_num = 0;
		answer = 1;
		for (i = 0; i < n; i++)
		{
			for (j = 0; j < n; j++)
			{
				scanf("%d", &(matrix[i][j]));
				max_num = max(max_num, matrix[i][j]);
			}
		}

		top_index = 0;

		for (i = 0; i < n; i++)
		{
			for (j = 0; j < n; j++)
			{
				if (matrix[i][j] == max_num)
				{
					top[top_index].x = j;
					top[top_index++].y = i;
				}
			}
		}

		for (i = 0; i < top_index; i++)
		{
			qx.push(top[i].x);
			qy.push(top[i].y);
			depth.push(1);
			solve(); //¾È ±ð¾ÒÀ» ¶§
		}

		for (tempk = 1; tempk <= k; tempk++)
		{
			for (i = 0; i < n; i++)
			{
				for (j = 0; j < n; j++)
				{
					tempmat = matrix[i][j];
					matrix[i][j] = max(0, matrix[i][j] - tempk);
					for (int ti = 0; ti < top_index; ti++)
					{
						qx.push(top[ti].x);
						qy.push(top[ti].y);
						depth.push(1);
						solve();
					}
					matrix[i][j] = tempmat;
				}
			}
		}
		printf("#%d %d\n", temp - t, answer);
	}

	return 0;
}