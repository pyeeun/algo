#include <iostream>
#include <algorithm>
#include <string.h>
#include <math.h>
using namespace std;

typedef struct BC
{
	int x;
	int y;
	int c;
	int p;
}BC;

typedef struct location
{
	int x;
	int y;
}location;

bool compare(BC a, BC b)
{
	return a.p > b.p;
}

int dx[5] = { 0, 0, 1, 0, -1 };
int dy[5] = { 0, -1, 0, 1, 0 };
int main()
{
	int t, temp;
	scanf("%d", &t);
	temp = t;
	int m, a;
	int person1[100];
	int person2[100];
	BC ap[8];
	int i, j, k;
	int check[11][11];
	location l1;
	location l2;
	int answer;
	int answertemp;
	int answertemp2;

	while (t--)
	{
		answer = 0;
		l1.x = 1, l1.y = 1;
		l2.x = 10, l2.y = 10;
		scanf("%d %d", &m, &a);
		memset(check, 0, sizeof(check));
		for (i = 0; i < m; i++)
			scanf("%d", &(person1[i]));
		for (i = 0; i < m; i++)
			scanf("%d", &(person2[i]));
		
		for (i = 0; i < a; i++)
			scanf("%d %d %d %d", &(ap[i].x), &(ap[i].y), &(ap[i].c), &(ap[i].p));

		sort(ap, ap + a, compare);

		for (i = 1; i <= 10; i++)
		{
			for (j = 1; j <= 10; j++)
			{
				for (k = 0; k < a; k++)
				{
					if (abs(j - ap[k].x) + abs(i - ap[k].y) <= ap[k].c)
					{
						check[i][j] = k + 1;
						break;
					}
				}
			}
		}

		for (i = 0; i <= m; i++)
		{
			answertemp = 0;
			answertemp2 = 0;

			//l1 -> l2 순서로 확인
			if (check[l1.y][l1.x] != 0)
			{
				answertemp += ap[check[l1.y][l1.x] - 1].p;
			}

			if (check[l2.y][l2.x] != 0)
			{
				if (check[l2.y][l2.x] == check[l1.y][l1.x])
				{
					for (k = 0; k < a; k++)
					{
						if (k == check[l2.y][l2.x] - 1)
							continue;
						else if (abs(l2.x - ap[k].x) + abs(l2.y - ap[k].y) <= ap[k].c)
						{
							answertemp += ap[k].p;
							break;
						}

					}
				}
				else
					answertemp += ap[check[l2.y][l2.x] - 1].p;
			}

			//l2 -> l1 순서로 확인
			if (check[l2.y][l2.x] != 0)
			{
				answertemp2 += ap[check[l2.y][l2.x] - 1].p;
			}

			if (check[l1.y][l1.x] != 0)
			{
				if (check[l1.y][l1.x] == check[l2.y][l2.x])
				{
					for (k = 0; k < a; k++)
					{
						if (k == check[l1.y][l1.x] - 1)
							continue;
						else if (abs(l1.x - ap[k].x) + abs(l1.y - ap[k].y) <= ap[k].c)
						{
							answertemp2 += ap[k].p;
							break;
						}

					}
				}
				else
					answertemp2 += ap[check[l1.y][l1.x] - 1].p;
			}

			answer += max(answertemp, answertemp2);
			if (i == m)
				break;
			l1.x += dx[person1[i]];
			l1.y += dy[person1[i]];
			l2.x += dx[person2[i]];
			l2.y += dy[person2[i]];
		}
		printf("#%d %d\n", temp - t, answer);
	}
	return 0;
}