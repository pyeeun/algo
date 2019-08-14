#define _CRT_SECURE_NO_WARNINGS
#include <iostream>
#include <cstring>
#include <vector>
#include <algorithm>
using namespace std;

int map[21][21];
vector<pair<int, int>> v;
int n, m; // 도시의 크기, 비용
int max_home = 0; // 손해를 보지 않으며 최대 서비스를 제공할 수 있는 집의 개수
int line = 1;

// 비용 계산
void solve(int x, int y, int size)
{
	int oppay = size * size + (size - 1) * (size - 1); // 운영비용
	int home = 0;
	int s = 1; // 마름모 증감 변수
	bool state = false; // 마름모의 중간 지점을 지났는지 체크

	for (int i = x - (size - 1); i <= x + (size - 1); i++)
	{
		for (int j = y - (s/2); j <= y + (s/2); j++)
		{
			if (i < 0 || j < 0 || i >= n || j >= n)
				continue;

			if (map[i][j] == 1) // 범위 안에 속하는 집 개수
			{
				home++;
			}
		}
		
		if (state == false) // 마름모의 위 부분
			s += 2;
		else // 마름모의 아래 부분
			s -= 2;

		if ((s / 2) + 1 == size) // 마름모의 중간 지점을 지나면 크기 감소
			state = true;
	}
	
	int advantage = home * m - oppay; // 집들을 통해 얻는 수익 - 운영비용

	if (advantage >= 0) // 수익이 발생한다면, 최대 집 개수 구함
		max_home = max(max_home, home);
}

int main()
{
	int t;
	scanf("%d", &t);

	while (t--)
	{
		// 초기화
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