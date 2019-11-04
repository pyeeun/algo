#include <iostream>
#include <string.h>
#include <algorithm>
using namespace std;

typedef struct _where
{
	int x;
	int y;
}_where;

int n;
int order[10];
int visited[10];
int min_num;
_where company;
_where home;
_where client[10];

int abs(int a, int b)
{
	if (a >= b)
		return a - b;
	else
		return b - a;
}

void solve()
{
	int distance = 0;
	int i;

	distance += abs(company.x, client[order[0]].x);
	distance += abs(company.y, client[order[0]].y);

	for (i = 0; i < n - 1; i++)
	{
		distance += abs(client[order[i]].x, client[order[i + 1]].x);
		distance += abs(client[order[i]].y, client[order[i + 1]].y);
	}

	distance += abs(home.x, client[order[n - 1]].x);
	distance += abs(home.y, client[order[n - 1]].y);

	min_num = min(min_num, distance);
}

void factorial(int k)
{
	if (k == n)
		solve();
	else
	{
		for (int i = 0; i < n; i++)
		{
			if (visited[i] == 1)
				continue;
			else
			{
				visited[i] = 1;
				order[k] = i;
				factorial(k + 1);
				visited[i] = 0;
			}
		}
	}
}

int main()
{
	int t, temp;
	int i;
	scanf("%d", &t);
	temp = t;
	while (t--)
	{
		scanf("%d", &n);
		scanf("%d %d %d %d", &(company.x), &(company.y), &(home.x), &(home.y));
		for (i = 0; i < n; i++)
			scanf("%d %d", &(client[i].x), &(client[i].y));
		memset(visited, 0, sizeof(visited));
		min_num = 10000000;
		factorial(0);
		printf("#%d %d\n", temp - t, min_num);
	}

	return 0;
}