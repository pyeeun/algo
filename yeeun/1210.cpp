#include <iostream>
#include <cstring>
using namespace std;

int map[101][101];
int visit[101][101];

int move(int x, int y)
{
	// 맨 윗줄에 도착했을 경우 종료
	if(x == 0)
		return y;

	visit[x][y] = 1; // 방문 표시

	if(map[x][y-1] == 1 && visit[x][y-1] == 0) 
		move(x, y-1); // 왼쪽 이동
	else if(map[x][y+1] == 1 && visit[x][y+1] == 0) 
		move(x, y+1); // 오른쪽 이동
	else 
		move(x-1, y); // 위로 이동
}

int main()
{
	for(int t=1; t<=10; t++)
	{
		memset(map, 0, sizeof(map));
		memset(visit, 0, sizeof(visit));

		int tc;
		scanf("%d", &tc);

		int x,y;
		for(int i=0; i<100; i++)
		{
			for(int j=0; j<100; j++)
			{
				scanf("%d", &map[i][j]);
				if(map[i][j] == 2)
				{
					x = i;
					y = j;
				}
			}
		}

		printf("#%d %d\n", tc, move(x-1,y));
	}
}