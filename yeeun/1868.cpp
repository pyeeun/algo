#include <iostream>
#include <cstring>
#include <vector>
using namespace std;

// 8방향
int dx[8] = { -1, -1, 0, 1, 1, 1, 0, -1 };
int dy[8] = { 0, 1, 1, 1, 0, -1, -1, -1 };

char c[301][301];
int map[301][301];
int visit[301][301];
vector<pair<int,int>> v;
int n;
int line = 1;

void dfs(int x, int y)
{
	visit[x][y] = 1;

	// 좌표가 0인 것들을 8방향으로 탐색하면서 영역을 넓혀감
	for(int dir=0; dir<8; dir++)
	{
		int nx = x + dx[dir];
		int ny = y + dy[dir];

		// 범위를 벗어날 경우
		if(nx < 0 || ny < 0 || nx >= n || ny >= n || visit[nx][ny] == 1)
			continue;

		if(map[nx][ny] == 0) // 주위에 0이 있을 경우
			dfs(nx, ny);
		else
			visit[nx][ny] = 1; // 방문 체크
	}
}
int main()
{
	int t;
	scanf("%d", &t);

	while(t--)
	{
		scanf("%d", &n);

		memset(map, 0, sizeof(map));
		memset(visit, 0, sizeof(visit));
		v.clear();

		for(int i=0; i<n; i++)
			for(int j=0; j<n; j++)
				scanf(" %c", &c[i][j]);

		for(int i=0; i<n; i++)
		{
			for(int j=0; j<n; j++)
			{
				for(int k=0; k<8; k++)
				{
					// 지뢰 표시
					if(c[i][j] == '*')
					{
						map[i][j] = -1;
						visit[i][j] = 1;
					}

					// 8방향으로 탐색
					int nx = i + dx[k];
					int ny = j + dy[k];

					// 8방향에 존재하는 지뢰 개수 저장
					if(c[nx][ny] == '*' && c[i][j] != '*')
						map[i][j] = map[i][j] + 1;
				}

				// 해당 좌표가 0일 경우, 벡터에 추가
				if(map[i][j] == 0)
					v.push_back(make_pair(i,j));
			}
		}

		int click = 0;
		// 8방향에 지뢰가 없어서 0을 갖는 좌표들을 탐색
		for(int i=0; i<v.size(); i++)
		{
			int x = v[i].first;
			int y = v[i].second;

			if(visit[x][y] == 0) // 방문을 안한 좌표라면
			{
				dfs(x,y);
				click = click + 1;
			}
		}

		// 0 주변 범위가 아니라서 탐색되지 않은 것들은
		// 각각 클릭의 개수를 증가시켜줌
		for(int i=0; i<n; i++)
		{
			for(int j=0; j<n; j++)
			{
				if(visit[i][j] == 0)
					click = click + 1;
			}
		}

		printf("#%d %d\n", line++, click);
	}
}