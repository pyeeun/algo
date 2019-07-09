#include <iostream>
#include <cstring>
#include <string>
#include <set>
#include<algorithm>
using namespace std;

// 상우하좌
int dx[4] = {-1, 0, 1, 0};
int dy[4] = {0, 1, 0, -1};

set<int> s; // 7자리 숫자 저장될 벡터
long long map[4][4];
int line = 1;

void dfs(int x, int y, string num)
{
	if(num.length() == 7) // 7글자가 완성되면 셋에 추가
	{
		s.insert(stoi(num));
	}
	else
	{
		for(int i=0; i<4; i++) // 4방향 탐색
		{
			int nx = x + dx[i];
			int ny = y + dy[i];

			// 배열 밖을 벗어날 수 없음
			if(nx < 0 || ny < 0 || nx >= 4 || ny >= 4)
				continue;
			else
			{
				string value = to_string(map[nx][ny]);
				dfs(nx, ny, num+value); // 다음 글자를 현재 글자에 이어붙여 탐색
			}
		}
	}
}

int main()
{
	int t;
	scanf("%d", &t);

	while(t--)
	{
		memset(map, 0, sizeof(map));
		s.clear();

		// 사용자로부터 4X4 배열 입력 받음
		for(int i=0; i<4; i++)
			for(int j=0; j<4; j++)
				scanf("%d", &map[i][j]);

		// (0,0)부터 (4,4)까지 모든 좌표 탐색
		for(int i=0; i<4; i++)
		{
			for(int j=0; j<4; j++)
			{
				dfs(i,j,to_string(map[i][j]));
			}
		}
		printf("#%d %d\n", line++, s.size());
	}
}