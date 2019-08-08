#include <iostream>
#include <string.h>
#include <vector>
using namespace std;

typedef struct micro
{
	int x;
	int y;
	int c;
	int d;
}micro;

typedef struct lotation
{
	int x;
	int y;
}lotation;

int dx[5] = { 0, 0 ,0 ,-1 ,1 };
int dy[5] = { 0, -1, 1, 0, 0 };

int cell[100][100];
int maxcell[100][100];
int direction[100][100];
int check[100][100];

vector<micro> v;
vector<micro> vtemp;
vector<lotation> lottemp;

int main()
{
	int t, temp;
	scanf("%d", &t);
	temp = t;
	int n, m, k;
	int i, j;
	int answer;
	while (t--)
	{
		v.clear();
		answer = 0;
		scanf("%d %d %d", &n, &m, &k);
		for (i = 0; i < k; i++)
		{
			micro m;
			scanf("%d %d %d %d", &(m.y), &(m.x), &(m.c), &(m.d));
			v.push_back(m);
		}

		
		for (i = 0; i < m; i++) // m 시간
		{
			memset(cell, 0, sizeof(cell));
			memset(maxcell, 0, sizeof(maxcell));
			memset(direction, 0, sizeof(direction));
			memset(check, 0, sizeof(check));
			lottemp.clear();
			for (j = 0; j < v.size(); j++)
			{
				lotation lot;
				lot.x = v[j].x + dx[v[j].d];
				lot.y = v[j].y + dy[v[j].d];
				lottemp.push_back(lot);
				// 2개 이상 합쳐질 경우를 생각해서 d 조정을 해야함.
				if (maxcell[lot.y][lot.x] < v[j].c)
				{
					maxcell[lot.y][lot.x] = v[j].c;
					direction[lot.y][lot.x] = v[j].d;
				}
				if (v[j].y + dy[v[j].d] == 0 || v[j].y + dy[v[j].d] == n - 1 || v[j].x + dx[v[j].d] == 0 || v[j].x + dx[v[j].d] == n - 1)
					cell[lot.y][lot.x] += v[j].c / 2;
				else
					cell[lot.y][lot.x] += v[j].c;
			}

			for (j = 0; j < lottemp.size(); j++)
			{

				micro mic;
				mic.x = lottemp[j].x;
				mic.y = lottemp[j].y;
				if (check[mic.y][mic.x] == 1)
					continue;
				check[mic.y][mic.x] = 1;
				mic.c = cell[mic.y][mic.x];
				mic.d = direction[mic.y][mic.x];
				if (mic.y == 0 || mic.y == n - 1 || mic.x == 0 || mic.x == n - 1)
				{
					if (mic.d == 1)
						mic.d = 2;
					else if (mic.d == 2)
						mic.d = 1;
					else if (mic.d == 3)
						mic.d = 4;
					else if (mic.d == 4)
						mic.d = 3;
				}
				vtemp.push_back(mic);
			}

			v = vtemp;
			vtemp.clear();
		}

		for (i = 0; i < v.size(); i++)
			answer += v[i].c;
		printf("#%d %d\n", temp - t, answer);
	}
	return 0;
}