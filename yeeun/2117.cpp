#define _CRT_SECURE_NO_WARNINGS
#include <iostream>
#include <cstring>
#include <vector>
#include <algorithm>
using namespace std;

int map[21][21];
vector<pair<int, int>> v;
int n, m; // ������ ũ��, ���
int max_home = 0; // ���ظ� ���� ������ �ִ� ���񽺸� ������ �� �ִ� ���� ����
int line = 1;

// ��� ���
void solve(int x, int y, int size)
{
	int oppay = size * size + (size - 1) * (size - 1); // ����
	int home = 0;
	int s = 1; // ������ ���� ����
	bool state = false; // �������� �߰� ������ �������� üũ

	for (int i = x - (size - 1); i <= x + (size - 1); i++)
	{
		for (int j = y - (s/2); j <= y + (s/2); j++)
		{
			if (i < 0 || j < 0 || i >= n || j >= n)
				continue;

			if (map[i][j] == 1) // ���� �ȿ� ���ϴ� �� ����
			{
				home++;
			}
		}
		
		if (state == false) // �������� �� �κ�
			s += 2;
		else // �������� �Ʒ� �κ�
			s -= 2;

		if ((s / 2) + 1 == size) // �������� �߰� ������ ������ ũ�� ����
			state = true;
	}
	
	int advantage = home * m - oppay; // ������ ���� ��� ���� - ����

	if (advantage >= 0) // ������ �߻��Ѵٸ�, �ִ� �� ���� ����
		max_home = max(max_home, home);
}

int main()
{
	int t;
	scanf("%d", &t);

	while (t--)
	{
		// �ʱ�ȭ
		memset(map, 0, sizeof(map));
		max_home = 0;

		scanf("%d %d", &n, &m);

		for (int i = 0; i < n; i++)
		{
			for (int j = 0; j < n; j++)
			{
				scanf("%d", &map[i][j]);
				if (map[i][j] == 1)
					v.push_back(make_pair(i, j));
			}
		}
		
		for (int i = 0; i < n; i++)
			for (int j = 0; j < n; j++)
				for(int k=0; k<=n+1; k++)
					solve(i, j, k);

		/*
		for (int i = 0; i < v.size(); i++)
			for(int k=0; k<=n+1; k++)
				solve(v[i].first, v[i].second, k);*/

		printf("#%d %d\n", line++, max_home);
	}
}