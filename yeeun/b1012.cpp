#define _CRT_SECURE_NO_WARNINGS
#include <iostream>
#include <queue>
using namespace std;

// 4���� �������
int dx[] = { -1, 0, 1, 0 };
int dy[] = { 0, 1, 0, -1 };

int m, n, k; // ����, ����, ���� ����
int map[51][51]; // ���߹�
int visit[51][51]; // �湮����
queue<pair<int, int>> q;

void bfs(int bug)
{
	while (!q.empty())
	{
		int cx = q.front().first;
		int cy = q.front().second;
		q.pop();

		for (int i = 0; i < 4; i++)
		{
			// ���� Ž���� ��ǥ
			int nx = cx + dx[i];
			int ny = cy + dy[i];

			// ������ ����� �ʰ�, 
			// ���߰� �ɾ��� �������� �湮���� ���� ���� ��� Ž��
			if (!(nx < 0 || ny < 0 || nx >= n || ny >= m) 
				&& visit[nx][ny] == 0 && map[nx][ny] == 1)
			{
				q.push(make_pair(nx, ny));
				visit[nx][ny] = bug;
			}
		}
	}
}
int main()
{
	int t;
	scanf("%d", &t);

	while (t--)
	{
		memset(map, 0, sizeof(map));
		memset(visit, 0, sizeof(visit));
		scanf("%d %d %d", &m, &n, &k);

		for (int i = 0; i < k; i++)
		{
			int x, y;
			scanf("%d %d", &y, &x);
			map[x][y] = 1;
		}

		int bug = 1; // ���� ������ ����

		// ��ǥ Ž��
		for (int i = 0; i < n; i++)
		{
			for (int j = 0; j < m; j++)
			{
				// ���߰� �ɾ��� �ְ�, �湮���� ���� ��ǥ�� ť�� ����
				if (map[i][j] == 1 && visit[i][j] == 0)
				{
					q.push(make_pair(i, j));
					visit[i][j] = bug;
					bfs(bug);

					bug++;
				}
			}
		}

		printf("%d\n", bug-1);
	}
}