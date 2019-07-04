#include <iostream>
#include <vector>
#include <cstring>
using namespace std;

// 왼쪽위를 기준으로 시계방향 
int dx[] = { -1, -1, -1, 0, 1, 1, 1, 0 };
int dy[] = { -1, 0, 1, 1, 1, 0, -1, -1 };

int map[9][9];
int n; // 보드 한 변의 길이
int m; // 돌을 놓는 횟수
int line = 1; // 테스트케이스 넘버링

int main()
{
	int t; // 테스트케이스의 개수
	scanf("%d", &t);

	while(t--)
	{
		scanf("%d %d", &n, &m);

		// 초기화
		int black_cnt = 0; // 흑돌의 개수
		int white_cnt = 0; // 백돌의 개수
		memset(map, 0, sizeof(map));

		int mid = n/2; // 초기에 위치할 중앙 돌 세팅
		map[mid][mid] = 2;
		map[mid][mid+1] = 1;
		map[mid+1][mid] = 1;
		map[mid+1][mid+1] = 2;

		for(int i=0; i<m; i++)
		{
			int x, y, stone;
			scanf("%d %d %d", &x, &y, &stone);
			map[y][x] = stone; // y행 x열

			// 상하좌우대각선 8방향 탐색
			for(int j=0; j<8; j++)
			{
				vector<pair<int,int>> v;
				
				int state = 0;
				int nx = y + dx[j];
				int ny = x + dy[j];

				// 보드 범위를 넘어가지 않은 경우 반복
				while(0 < nx && 0 < ny && nx <= n && ny <= n)
				{
					if(map[nx][ny] == 0) // 돌이 없는 경우
						break;
					else if(map[nx][ny] != stone)
					{
						// 현재 놓여진 돌과 색은 다르지만
						// 변경될 수도 있는 돌의 좌표를 저장
						v.push_back(make_pair(nx,ny));
					}
					else if(map[nx][ny] == stone)
					{
						// 8방향에 같은 색 돌이 있을 경우
						state = 1; // 사이에 있는 돌 변경 확정
						break;
					}

					nx += dx[j]; // 위치 변경
					ny += dy[j]; // 위치 변경
				}

				// 같은 색의 돌이 8방향에 하나라도 존재할 경우
				if(state == 1)
				{
					for(int list=0; list<v.size(); list++)
					{
						// 미리 저장해두었던 좌표의 돌의 색을 바꿈
						int change_x = v[list].first;
						int change_y = v[list].second;
						map[change_x][change_y] = stone;
					}
				}
			}
		}

		// 흑돌, 백돌 개수 체크
		for(int i=1; i<=n; i++)
		{
			for(int j=1; j<=n; j++)
			{
				if(map[i][j] == 1) // 흑돌
					black_cnt = black_cnt + 1;
				else if(map[i][j] == 2) // 백돌
					white_cnt = white_cnt + 1;
			}
		}
		printf("#%d %d %d\n", line++, black_cnt, white_cnt);
	}
}

