#define _CRT_SECURE_NO_WARNINGS
#include <iostream>
#include <queue>
using namespace std;

// 토마토 구조체
struct tomato
{
	int x, y, day; // 좌표, 일
};

// 상우하좌
int dx[] = { -1, 0, 1, 0 };
int dy[] = { 0, 1, 0, -1 };

queue<tomato> q;
int n, m;
int box[1001][1001];
int res = 0;

int getTomato()
{
	int state = 1; // 토마토 상태

	// 박스 안의 모든 토마토 탐색
	for (int i = 0; i < m; i++)
	{
		for (int j = 0; j < n; j++)
		{
			if (box[i][j] == 0) // 하나라도 안 익었을 경우, 리턴
				return -1;
			else
				res = max(res, box[i][j]); // 모든 토마토가 익을 수 있는 최소 기간(최대값) 저장
		}
	}
	return state;
}

void bfs()
{
	while (!q.empty())
	{
		// 현재 토마토의 정보
		int cx = q.front().x;
		int cy = q.front().y;
		int cm = q.front().day;
		q.pop();

		// 상하좌우로 탐색
		for (int i = 0; i < 4; i++)
		{
			int nx = cx + dx[i];
			int ny = cy + dy[i];
			int nd = cm + 1;

			// 범위를 넘어가지 않고, 다음 토마토가 익지 않은 토마토이고,
			// 현재 토마토는 익은 토마토일 경우만 큐에 넣음
			if (!(nx < 0 || ny < 0 || nx >= m || ny >= n) 
				&& box[nx][ny] == 0 && box[cx][cy] >= 1)
			{
				q.push({ nx, ny, nd });
				box[nx][ny] = nd;
			}
		}
	}
}

int main()
{
	int emptybox = 0;
	scanf("%d %d", &n, &m);

	for (int i = 0; i < m; i++)
	{
		for (int j = 0; j < n; j++)
		{
			scanf("%d", &box[i][j]);

			if (box[i][j] == 1) // 익은 토마토일 경우
				q.push({ i, j, 0 });
			else if (box[i][j] == -1) // 빈 박스일 경우
				emptybox++;
		}
	}

	// 박스 안에 있는 토마토가 모두 익은 토마토일 경우
	if ((q.size() + emptybox) == (n * m))
		printf("0");
	else
	{
		bfs();

		if (getTomato() == -1) // 토마토가 모두 익지 않았을 경우
			printf("-1");
		else // 토마토가 모두 익었을 경우
			printf("%d", res);
	}
}