#include <iostream>
#include <queue>
#include <string.h>
using namespace std;

queue<int> qx;
queue<int> qy;
queue<int> times;
int n, m; //n : 세로, m : 가로
int r, c, l; //r : 세로, c : 가로, l : 시간
int matrix[50][50];
int visited[50][50];
int x, y, now_times;
int answer;

void dir(int a)// 0 1 2 3 : 상 하 좌 우
{
	int k;
	if (a == 0)
	{
		if (y - 1 >= 0 && visited[y - 1][x] == 0)
		{
			k = matrix[y - 1][x];
			if (k == 1 || k == 2 || k == 5 || k == 6)
			{
				qx.push(x);
				qy.push(y - 1);
				times.push(now_times + 1);
				visited[y - 1][x] = 1;
				answer++;
			}
		}
	}
	else if (a == 1)
	{
		if (y + 1 < n && visited[y + 1][x] == 0)
		{
			k = matrix[y + 1][x];
			if (k == 1 || k == 2 || k == 4 || k == 7)
			{
				qx.push(x);
				qy.push(y + 1);
				times.push(now_times + 1);
				visited[y + 1][x] = 1;
				answer++;
			}
		}
	}
	else if (a == 2)
	{
		if (x - 1 >= 0 && visited[y][x - 1] == 0)
		{
			k = matrix[y][x - 1];
			if (k == 1 || k == 3 || k == 4 || k == 5)
			{
				qx.push(x - 1);
				qy.push(y);
				times.push(now_times + 1);
				visited[y][x - 1] = 1;
				answer++;
			}
		}
	}
	else if (a == 3)
	{
		if (x + 1 < m && visited[y][x + 1] == 0)
		{
			k = matrix[y][x + 1];
			if (k == 1 || k == 3 || k == 6 || k == 7)
			{
				qx.push(x + 1);
				qy.push(y);
				times.push(now_times + 1);
				visited[y][x + 1] = 1;
				answer++;
			}
		}
	}
}
void solve(int a)
{
	if (a == 1)
	{
		dir(0);
		dir(1);
		dir(2);
		dir(3);
	}
	else if (a == 2)
	{
		dir(0);
		dir(1);
	}
	else if (a == 3)
	{
		dir(2);
		dir(3);
	}
	else if (a == 4)
	{
		dir(0);
		dir(3);
	}
	else if (a == 5)
	{
		dir(1);
		dir(3);
	}
	else if (a == 6)
	{
		dir(1);
		dir(2);
	}
	else if (a == 7)
	{
		dir(0);
		dir(2);
	}
}

int main()
{
	int t, temp;
	scanf("%d", &t);
	int i, j;
	temp = t;
	while (t--)
	{
		scanf("%d %d %d %d %d", &n, &m, &r, &c, &l);
		for (i = 0; i < n; i++)
			for (j = 0; j < m; j++)
				scanf("%d", &(matrix[i][j]));
		memset(visited, 0, sizeof(visited));
		qx.push(c);
		qy.push(r);
		times.push(1);
		visited[r][c] = 1;
		if (matrix[r][c] != 0)
			answer = 1;
		else
			answer = 0;

		while (!qx.empty())
		{
			if (answer == 0)
				break;
			x = qx.front();
			y = qy.front();
			now_times = times.front();
			if (now_times >= l)
				break;
			solve(matrix[y][x]);
			qx.pop();
			qy.pop();
			times.pop();
		}
		while (!qx.empty())
		{
			qx.pop();
			qy.pop();
			times.pop();
		}
		printf("#%d %d\n", temp - t, answer);
	}

	return 0;
}