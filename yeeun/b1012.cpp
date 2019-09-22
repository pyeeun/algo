#define _CRT_SECURE_NO_WARNINGS
#include <iostream>
#include <queue>
using namespace std;

// 4방향 상우하좌
int dx[] = { -1, 0, 1, 0 };
int dy[] = { 0, 1, 0, -1 };

int m, n, k; // 가로, 세로, 배추 개수
int map[51][51]; // 배추밭
int visit[51][51]; // 방문여부
queue<pair<int, int>> q;

void bfs(int bug)
{
	while (!q.empty())
	{
		int cx = q.front().first;
		int cy = q.front().second;
		q.pop();

		for (int i = 0; i < 4; i++)
		{
			// 다음 탐색할 좌표
			int nx = cx + dx[i];
			int ny = cy + dy[i];

			// 범위를 벗어나지 않고, 
			// 배추가 심어진 곳이지만 방문하지 않은 곳일 경우 탐색
			if (!(nx < 0 || ny < 0 || nx >= n || ny >= m) 
				&& visit[nx][ny] == 0 && map[nx][ny] == 1)
			{
				q.push(make_pair(nx, ny));
				visit[nx][ny] = bug;
			}
		}
	}
}
int main()
{
	int t;
	scanf("%d", &t);

	while (t--)
	{
		memset(map, 0, sizeof(map));
		memset(visit, 0, sizeof(visit));
		scanf("%d %d %d", &m, &n, &k);

		for (int i = 0; i < k; i++)
		{
			int x, y;
			scanf("%d %d", &y, &x);
			map[x][y] = 1;
		}

		int bug = 1; // 배추 벌레의 개수

		// 좌표 탐색
		for (int i = 0; i < n; i++)
		{
			for (int j = 0; j < m; j++)
			{
				// 배추가 심어져 있고, 방문하지 않은 좌표를 큐에 넣음
				if (map[i][j] == 1 && visit[i][j] == 0)
				{
					q.push(make_pair(i, j));
					visit[i][j] = bug;
					bfs(bug);

					bug++;
				}
			}
		}

		printf("%d\n", bug-1);
	}
}