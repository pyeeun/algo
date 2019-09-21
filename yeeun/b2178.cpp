#define _CRT_SECURE_NO_WARNINGS
#include <iostream>
#include <queue>
using namespace std;

struct block
{
	int x, y, move;
};
// 상우하좌
int dx[] = { -1, 0, 1, 0 };
int dy[] = { 0, 1, 0, -1 };

queue<block> q; // 좌표
int map[101][101]; // 미로 배열
bool visit[101][101]; // 방문 여부
int n, m;
int res = 9876543; // 최소 칸수

void bfs()
{
	while (!q.empty())
	{
		int cx = q.front().x;
		int cy = q.front().y;
		int cm = q.front().move;

		q.pop();

		// 도착 지점일 경우
		if ((cx == n - 1) && (cy == m - 1))
		{
			res = min(res, cm);
			return;
		}

		for (int i = 0; i < 4; i++)
		{
			int nx = cx + dx[i];
			int ny = cy + dy[i];
			int nm = cm + 1;

			// 범위를 벗어나지 않는 경우만 수행
			if ((!(nx < 0 || ny < 0 || nx >= n || ny >= m)) && map[nx][ny] == 1 && visit[nx][ny] == false)
			{
				q.push({ nx,ny,nm });
				visit[nx][ny] = true;
			}
		}
	}
	
}
int main()
{
	scanf("%d %d", &n, &m);

	for (int i = 0; i < n; i++)
		for (int j = 0; j < m; j++)
			scanf("%1d", &map[i][j]);

	q.push({ 0,0,1 });
	visit[0][0] = true;

	bfs();
	printf("%d", res);
}