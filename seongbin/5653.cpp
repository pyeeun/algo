#include <iostream>
#include <string.h>
#include <vector>
#include <algorithm>
using namespace std;

//상하좌우
int dx[4] = { 0, 0, -1, 1 };
int dy[4] = { -1, 1, 0, 0 };

typedef struct
{
	int life;
	int time;
	int x;
	int y;
	int die;
}cell;
int matrixlife[700][700] = { 0 };
int check[700][700] = { 0 };
vector <cell> v;

bool compare(cell a, cell b)
{
	if (a.die == 1)
		return false;
	else if (b.die == 1)
		return true;
	else
		return a.life < b.life;
}

int main()
{
	int t;
	int temp;
	scanf("%d", &t);
	temp = t;
	int n, m, k;
	int i, j;
	int l;
	int dindex;
	int nx, ny;
	int vnum;
	int dienum = 0;
	cell c;
	while (t--)
	{
		scanf("%d %d %d", &n, &m, &k);
		for (i = 350 - n / 2; i < 350 + n / 2 + n % 2; i++)
		{
			for (j = 350 - m / 2; j < 350 + m / 2 + m % 2; j++)
			{
				scanf("%d", &(matrixlife[i][j]));
				if (matrixlife[i][j] == 0)
					continue;
				c.life = matrixlife[i][j];
				c.time = 0;
				c.x = j;
				c.y = i;
				c.die = 0;
				v.push_back(c);
				check[i][j] = 1;
			}
		}

		//현재 l시간 후 상태, loop에서 l + 1 시간 후의 상태를 만들고 싶음.
		for (l = 1; l <= k; l++)
		{
			sort(v.begin(), v.end(), compare);
			for (i = 0; i < dienum; i++)
				v.pop_back();
			vnum = v.size();
			for (i = 0; i < vnum; i++)
			{
				if (v[i].time >= v[i].life && v[i].time < 2 * v[i].life)
				{
					for (dindex = 0; dindex < 4; dindex++)
					{
						nx = v[i].x + dx[dindex];
						ny = v[i].y + dy[dindex];
						matrixlife[ny][nx] = v[i].life;
					}
				}
			}

			dienum = 0;
			for (i = 0; i < vnum; i++)
			{
				if (v[i].time >= v[i].life && v[i].time < 2 * v[i].life)
				{
					for (dindex = 0; dindex < 4; dindex++)
					{
						nx = v[i].x + dx[dindex];
						ny = v[i].y + dy[dindex];
						if (check[ny][nx] == 0)
						{
							check[ny][nx] = 1;
							c.life = matrixlife[ny][nx];
							c.x = nx;
							c.y = ny;
							c.die = 0;
							v.push_back(c);
						}
					}
				}

				v[i].time++;
				if (v[i].time >= 2 * v[i].life)
				{
					v[i].die = 1;
					dienum++;
				}
			}
		}
		printf("#%d %d\n", temp - t, v.size() - dienum);
		memset(matrixlife, 0, sizeof(matrixlife));
		memset(check, 0, sizeof(check));
		v.clear();
		dienum = 0;
	}
	return 0;
}