#include <iostream>
#include <vector>
#include <cstring>
using namespace std;

// �������� �������� �ð���� 
int dx[] = { -1, -1, -1, 0, 1, 1, 1, 0 };
int dy[] = { -1, 0, 1, 1, 1, 0, -1, -1 };

int map[9][9];
int n; // ���� �� ���� ����
int m; // ���� ���� Ƚ��
int line = 1; // �׽�Ʈ���̽� �ѹ���

int main()
{
	int t; // �׽�Ʈ���̽��� ����
	scanf("%d", &t);

	while(t--)
	{
		scanf("%d %d", &n, &m);

		// �ʱ�ȭ
		int black_cnt = 0; // �浹�� ����
		int white_cnt = 0; // �鵹�� ����
		memset(map, 0, sizeof(map));

		int mid = n/2; // �ʱ⿡ ��ġ�� �߾� �� ����
		map[mid][mid] = 2;
		map[mid][mid+1] = 1;
		map[mid+1][mid] = 1;
		map[mid+1][mid+1] = 2;

		for(int i=0; i<m; i++)
		{
			int x, y, stone;
			scanf("%d %d %d", &x, &y, &stone);
			map[y][x] = stone; // y�� x��

			// �����¿�밢�� 8���� Ž��
			for(int j=0; j<8; j++)
			{
				vector<pair<int,int>> v;
				
				int state = 0;
				int nx = y + dx[j];
				int ny = x + dy[j];

				// ���� ������ �Ѿ�� ���� ��� �ݺ�
				while(0 < nx && 0 < ny && nx <= n && ny <= n)
				{
					if(map[nx][ny] == 0) // ���� ���� ���
						break;
					else if(map[nx][ny] != stone)
					{
						// ���� ������ ���� ���� �ٸ�����
						// ����� ���� �ִ� ���� ��ǥ�� ����
						v.push_back(make_pair(nx,ny));
					}
					else if(map[nx][ny] == stone)
					{
						// 8���⿡ ���� �� ���� ���� ���
						state = 1; // ���̿� �ִ� �� ���� Ȯ��
						break;
					}

					nx += dx[j]; // ��ġ ����
					ny += dy[j]; // ��ġ ����
				}

				// ���� ���� ���� 8���⿡ �ϳ��� ������ ���
				if(state == 1)
				{
					for(int list=0; list<v.size(); list++)
					{
						// �̸� �����صξ��� ��ǥ�� ���� ���� �ٲ�
						int change_x = v[list].first;
						int change_y = v[list].second;
						map[change_x][change_y] = stone;
					}
				}
			}
		}

		// �浹, �鵹 ���� üũ
		for(int i=1; i<=n; i++)
		{
			for(int j=1; j<=n; j++)
			{
				if(map[i][j] == 1) // �浹
					black_cnt = black_cnt + 1;
				else if(map[i][j] == 2) // �鵹
					white_cnt = white_cnt + 1;
			}
		}
		printf("#%d %d %d\n", line++, black_cnt, white_cnt);
	}
}

