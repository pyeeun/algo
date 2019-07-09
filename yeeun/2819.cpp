#include <iostream>
#include <cstring>
#include <string>
#include <set>
#include<algorithm>
using namespace std;

// �������
int dx[4] = {-1, 0, 1, 0};
int dy[4] = {0, 1, 0, -1};

set<int> s; // 7�ڸ� ���� ����� ����
long long map[4][4];
int line = 1;

void dfs(int x, int y, string num)
{
	if(num.length() == 7) // 7���ڰ� �ϼ��Ǹ� �¿� �߰�
	{
		s.insert(stoi(num));
	}
	else
	{
		for(int i=0; i<4; i++) // 4���� Ž��
		{
			int nx = x + dx[i];
			int ny = y + dy[i];

			// �迭 ���� ��� �� ����
			if(nx < 0 || ny < 0 || nx >= 4 || ny >= 4)
				continue;
			else
			{
				string value = to_string(map[nx][ny]);
				dfs(nx, ny, num+value); // ���� ���ڸ� ���� ���ڿ� �̾�ٿ� Ž��
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

		// ����ڷκ��� 4X4 �迭 �Է� ����
		for(int i=0; i<4; i++)
			for(int j=0; j<4; j++)
				scanf("%d", &map[i][j]);

		// (0,0)���� (4,4)���� ��� ��ǥ Ž��
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