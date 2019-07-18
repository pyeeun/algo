#include <iostream>
#include <cstring>
#include <vector>
using namespace std;

int map[21][21];
int built[21][21];
int builtYN[21][2]; // ������ ������ ��ġ ���� ����
int t,line = 1;
int n, x; // ���� ����, ���� ����

int main()
{
	scanf("%d", &t);
	while(t--)
	{
		memset(map, 0, sizeof(map));
		memset(built, 0, sizeof(built));
		memset(builtYN, 0, sizeof(builtYN));
		scanf("%d %d", &n, &x);

		// �Է¹ޱ�
		for(int i=0; i<n; i++)
			for(int j=0; j<n; j++)
				scanf("%d", &map[i][j]);

		// ���� ���� �˻�
		for(int i=0; i<n; i++)
		{	
			int prev = map[i][0];
			for(int j=1; j<n; j++)
			{
				bool same = true;
				// ���� ��ǥ���� �ٸ��� ������ ���� ��� ���� ��ġ �ʿ�
				if(prev != map[i][j] && prev > map[i][j])
				{
					for(int k=j; k<j+x; k++)
					{
						// ������ �ٸ��ų�, ������ ���̰� ������ �̹� ��ġ�߰ų�, ���̰� 1 �Ѱ� ���̳� ���
						if(map[i][j] != map[i][k] || (map[i][j] == map[i][k] && built[i][k] != 0) || abs(prev - map[i][j]) > 1)
						{
							same = false;
							break;
						}
					}
					if(same == true)
					{
						for(int k=j; k<j+x; k++)
							built[i][k] = 1; // ���� ��ġ
					}
					else
					{
						builtYN[i][0] = -1; // �� ���ο��� ���� ��ġ �Ұ�
						break;
					}
				}
				// ���� ��ǥ���� �ٸ��� ������ ���� ���, ���� ������ ���� ��ġ �ʿ�
				else if(prev != map[i][j] && prev < map[i][j])
				{
					same = true;
					for(int k=j-1; k>=j-x; k--)
					{
						if(prev != map[i][k] || (prev == map[i][k] && built[i][k] != 0) || abs(prev - map[i][j]) > 1)
						{
							same = false;
							break;
						}
					}
					if(same == true)
					{
						for(int k=j-1; k<prev-x+1; k++)
							built[i][k] = 1; // ���� ��ġ
					}
					else
					{
						builtYN[i][0] = -1; // ���� ��ġ �Ұ�
						break;
					}
				}
				prev = map[i][j];
			}
		}
		
		memset(built, 0, sizeof(built)); // ���� ��ġ �ʱ�ȭ

		// ���� ���� �˻�
		for(int i=0; i<n; i++)
		{	
			int prev = map[0][i];
			for(int j=1; j<n; j++)
			{
				bool same = true;
				// ���� ��ǥ���� �ٸ��� ������ ���� ��� ���� ��ġ �ʿ�
				if(prev != map[j][i] && prev > map[j][i])
				{
					for(int k=j; k<j+x; k++)
					{
						// ������ �ٸ��ų�, ������ ���̰� ������ �̹� ��ġ�߰ų�, ���̰� 1 �Ѱ� ���̳� ���
						if(map[j][i] != map[k][i] || (map[j][i] == map[k][i] && built[k][i] != 0) || abs(prev - map[j][i]) > 1)
						{
							same = false;
							break;
						}
					}
					if(same == true)
					{
						for(int k=j; k<j+x; k++)
							built[k][i] = 1; // ���� ��ġ
					}
					else
					{
						builtYN[i][1] = -1;
						break;
					}
				}
				// ���� ��ǥ���� �ٸ��� ������ ���� ���, ���� ������ ���� ��ġ �ʿ�
				else if(prev != map[j][i] && prev < map[j][i])
				{
					same = true;
					for(int k=j-1; k>=j-x; k--)
					{
						if(prev != map[k][i] || (prev == map[k][i] && built[k][i] != 0) || abs(prev - map[j][i]) > 1)
						{
							same = false;
							break;
						}
					}
					if(same == true)
					{
						for(int k=j-1; k<prev-x+1; k++)
							built[k][i] = 1; // ���� ��ġ
					}
					else
					{
						builtYN[i][1] = -1;
						break;
					}
				}
				prev = map[j][i];
			}
		}

		// ���θ� ��ġ�� �� ���� ������ ������ ������ ����
		int result = 0;
		for(int i=0; i<n; i++)
			for(int j=0; j<2; j++)
				if(builtYN[i][j] != -1)
					result += 1;

		printf("#%d %d\n", line++, result);
	}
}