#include <iostream>
#include <string.h>
#include <queue>
#include <algorithm>
using namespace std;

typedef struct node
{
	int x, y, dist;
	node(int _x, int _y, int _dist) : x(_x), y(_y), dist(_dist) {}
	bool operator > (const node& n) const
	{
		return dist > n.dist;
	}

}node;

priority_queue<node, vector<node>, greater<node>> pq;

int matrix[100][100];
int answer[100][100];
int visit[100][100];
//»óÇÏÁÂ¿ì
int dx[4] = { 0, 0, -1, 1 };
int dy[4] = { -1, 1, 0, 0 };
int n;

void dijkstra()
{
	while (!pq.empty())
	{
		int x = pq.top().x;
		int y = pq.top().y;
		int d = pq.top().dist;
		pq.pop();
		if (x == n - 1 && y == n - 1)
			continue;

		for (int dindex = 0; dindex < 4; dindex++)
		{
			int nx = x + dx[dindex];
			int ny = y + dy[dindex];

			if (nx < 0 || ny < 0 || nx >= n || ny >= n)
				continue;

			if (answer[ny][nx] > answer[y][x] + matrix[ny][nx])
			{
				answer[ny][nx] = answer[y][x] + matrix[ny][nx];
				pq.push(node(nx, ny, matrix[ny][nx]));
			}
		}
	}
}

int main()
{
	int t, temp;
	scanf("%d", &t);
	temp = t;
	int i, j;
	while (t--)
	{
		memset(answer, 9999999, sizeof(answer));
		memset(visit, 0, sizeof(visit));
		scanf("%d", &n);
		for (i = 0; i < n; i++)
			for (j = 0; j < n; j++)
				scanf("%1d", &(matrix[i][j]));

		pq.push(node(0, 0, matrix[0][0]));
		answer[0][0] = 0;
		dijkstra();

		printf("#%d %d\n", temp - t, answer[n - 1][n - 1]);
	}
	return 0;
}