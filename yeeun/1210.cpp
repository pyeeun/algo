#include <iostream>
#include <cstring>
using namespace std;

int map[101][101];
int visit[101][101];

int move(int x, int y)
{
	// �� ���ٿ� �������� ��� ����
	if(x == 0)
		return y;

	visit[x][y] = 1; // �湮 ǥ��

	if(map[x][y-1] == 1 && visit[x][y-1] == 0) 
		move(x, y-1); // ���� �̵�
	else if(map[x][y+1] == 1 && visit[x][y+1] == 0) 
		move(x, y+1); // ������ �̵�
	else 
		move(x-1, y); // ���� �̵�
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