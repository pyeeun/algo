#define _CRT_SECURE_NO_WARNINGS
#include <iostream>
#include <queue>
#include <vector>
#include <cstring>
using namespace std;

int N, M, EmptyCount;

// 상우하좌
int dx[] = { -1, 0, 1, 0 };
int dy[] = { 0, 1, 0, -1 };

vector<pair<int, int>> virus;
int map[51][51];
int time[51][51];
int sel[10];
int ans = 9876543;

void Spread(queue<pair<int, int>> q)
{
	int spread_place = 0;
	int atime = 0;

	while (!q.empty())
	{
		int x = q.front().first;
		int y = q.front().second;
		q.pop();

		for (int i = 0; i < 4; i++)
		{
			int nx = x + dx[i];
			int ny = y + dy[i];

			// 연구소 범위를 벗어나지 않은 경우
			if (!(nx < 0 || ny < 0 || nx >= N || ny >= N))
			{
				if (map[nx][ny] != 1 && time[nx][ny] == -1)
				{
					time[nx][ny] = time[x][y] + 1;

					if (map[nx][ny] == 0)
					{
						spread_place++;
						atime = time[nx][ny];
					}
					q.push(make_pair(nx, ny));
				}
			}
		}
	}

	if (EmptyCount == spread_place)
	{
		ans = min(ans, atime);
	}
}
void Select(int idx, int cnt)
{
	if (cnt == M)
	{
		queue<pair<int, int>> q;
		memset(time, -1, sizeof(time));
		for (int i = 0; i < virus.size(); i++)
		{
			if (sel[i] == 1) // 선택된 바이러스일 경우
			{
				q.push(make_pair(virus[i].first, virus[i].second));
				time[virus[i].first][virus[i].second] = 0;
			}
		}

		Spread(q);
		return;
	}

	for (int i = idx; i < virus.size(); i++)
	{
		if (sel[i] == 1) continue;
		sel[i] = 1;
		Select(i + 1, cnt + 1);
		sel[i] = 0;
	}
}
int main()
{
	scanf("%d %d", &N, &M);
	
	for (int i = 0; i < N; i++)
	{
		for (int j = 0; j < N; j++)
		{
			scanf("%d", &map[i][j]);
			if (map[i][j] == 0) EmptyCount++; // 빈 공간 카운트
			else if (map[i][j] == 2) virus.push_back(make_pair(i, j)); // 좌표 저장
		}
	}

	Select(0, 0);

	if (ans == 9876543)
		printf("-1");
	else
		printf("%d", ans);
}