#include <iostream>
#include <cstring>
#include <vector>
using namespace std;

// 8����
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

	// ��ǥ�� 0�� �͵��� 8�������� Ž���ϸ鼭 ������ ������
	for(int dir=0; dir<8; dir++)
	{
		int nx = x + dx[dir];
		int ny = y + dy[dir];

		// ������ ��� ���
		if(nx < 0 || ny < 0 || nx >= n || ny >= n || visit[nx][ny] == 1)
			continue;

		if(map[nx][ny] == 0) // ������ 0�� ���� ���
			dfs(nx, ny);
		else
			visit[nx][ny] = 1; // �湮 üũ
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
					// ���� ǥ��
					if(c[i][j] == '*')
					{
						map[i][j] = -1;
						visit[i][j] = 1;
					}

					// 8�������� Ž��
					int nx = i + dx[k];
					int ny = j + dy[k];

					// 8���⿡ �����ϴ� ���� ���� ����
					if(c[nx][ny] == '*' && c[i][j] != '*')
						map[i][j] = map[i][j] + 1;
				}

				// �ش� ��ǥ�� 0�� ���, ���Ϳ� �߰�
				if(map[i][j] == 0)
					v.push_back(make_pair(i,j));
			}
		}

		int click = 0;
		// 8���⿡ ���ڰ� ��� 0�� ���� ��ǥ���� Ž��
		for(int i=0; i<v.size(); i++)
		{
			int x = v[i].first;
			int y = v[i].second;

			if(visit[x][y] == 0) // �湮�� ���� ��ǥ���
			{
				dfs(x,y);
				click = click + 1;
			}
		}

		// 0 �ֺ� ������ �ƴ϶� Ž������ ���� �͵���
		// ���� Ŭ���� ������ ����������
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