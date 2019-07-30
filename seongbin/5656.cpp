#include <iostream>
#include <vector>
#include <queue>
#include <string.h>
using namespace std;

vector<vector<int>> v;
vector<vector<int>> v2;
queue<int> q;
int n, w, h;
int perm_r[4];
int min = 200;
int matrix[15][12];//matrix[h][w]

//상하좌우
int dx[4] = { 0, 0, -1, 1 };
int dy[4] = { 1, -1, 0, 0 };
int times, maxtimes;
int totalbox;

void breakingbox(int num, int y, int x)
{
	v2[x][y] = 0;
	times++;
	if (num == 1)
	{
		return;
	}
	else
	{
		int nx, ny;
		for (int i = 0; i < 4; i++)
		{
			for (int j = 1; j < num; j++)
			{
				nx = x + dx[i] * j;
				ny = y + dy[i] * j;
				if (ny < 0 || nx < 0 || ny >= h || nx >= w)
					break;
				else if (ny >= v2[nx].size())
					continue;
				if (v2[nx][ny] == 0)
					continue;
				breakingbox(v2[nx][ny], ny, nx);
			}
		}
	}
}

void sortbox()
{
	vector<int> vtemp;
	for (int i = 0; i < w; i++)
	{
		for (int j = 0; j < v2[i].size(); j++)
		{
			if (v2[i][j] != 0)
				vtemp.push_back(v2[i][j]);
		}
		v2[i] = vtemp;
		vtemp.clear();
	}
}

void solve()
{
	v2 = v;
	int num;
	int wherebox;
	times = 0;
	for (int i = 0; i < n; i++)
	{
		if (v2[perm_r[i]].empty())
			continue;
		//memset(visit, 0, sizeof(visit));
		wherebox = v2[perm_r[i]].size();
		num = v2[perm_r[i]][wherebox - 1];
		breakingbox(num, wherebox - 1, perm_r[i]);

		//0인거를 제일 뒤로 빼고, 0인 것 pop 하면 완성할듯.
		sortbox();
	}

	
	if (times > maxtimes)
		maxtimes = times;

	/*if (maxtimes == totalbox)
		return;*/
}

void nPr(int count)
{
	if (count == n)
	{
		solve();
	}
	else
	{
		for (int i = 0; i < w; i++)
		{
			perm_r[count] = i;
			nPr(count + 1);
		}
	}
}

int main()
{
	int t, temp;
	scanf("%d", &t);
	temp = t;


	while (t--)
	{
		totalbox = 0;
		maxtimes = 0;
		v.clear();

		scanf("%d %d %d", &n, &w, &h);
		int i, j;
		for (i = 0; i < h; i++)
			for (j = 0; j < w; j++)
				scanf("%d", &(matrix[i][j]));

		vector<int> vtemp;
		for (j = 0; j < w; j++)
		{
			for (i = h - 1; i >= 0; i--)
			{
				if (matrix[i][j] == 0)
					break;
				vtemp.push_back(matrix[i][j]);
				totalbox++;
			}
			v.push_back(vtemp);
			vtemp.clear();
		}

		nPr(0);
		printf("#%d %d\n", temp - t, totalbox - maxtimes);

	}
	return 0;
}