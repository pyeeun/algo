#include <iostream>
#include <algorithm>
#include <string.h>
using namespace std;

int d, w, k;
int matrix[13][20];
int x;
int com[13];
int checkmatrix[13];
int alright;

void test()
{
	int i, j;
	int minnum;
	for (j = 0; j < w; j++)
	{
		minnum = 1;
		for (i = 1; i < d; i++)
		{
			if (matrix[i - 1][j] == matrix[i][j])
				minnum++;
			else
				minnum = 1;
			if (minnum >= k)
				break;
		}
		if (i == d)
			return;
	}
	alright = 1;
}

void insert_drug(int n)
{
	if (n == x)
	{
		test();
	}
	else
	{
		if (alright == 1)
			return;

		int tempmatrix[20];
		int i;
		for (i = 0; i < w; i++)
		{
			tempmatrix[i] = matrix[com[n]][i];
			matrix[com[n]][i] = 0;
		}
		insert_drug(n + 1);
		
		for (i = 0; i < w; i++)
			matrix[com[n]][i] = 1;
		insert_drug(n + 1);

		for (i = 0; i < w; i++)
			matrix[com[n]][i] = tempmatrix[i];
	}
}

void dCx(int count)
{
	if (count == x)
	{
		insert_drug(0);
		if (alright == 1)
			return;
	}
	else
	{
		if (alright == 1)
			return;
		int i;
		if (count == 0)
			i = 0;
		else
			i = com[count - 1];

		for (i; i < d; i++)
		{
			if (checkmatrix[i] == 1)
				continue;
			com[count] = i;
			checkmatrix[i] = 1;
			dCx(count + 1);
			checkmatrix[i] = 0;
		}
	}
}

int main()
{
	int t, temp;
	scanf("%d", &t);
	temp = t;
	int i, j;

	while (t--)
	{	
		scanf("%d %d %d", &d, &w, &k);
		for (i = 0; i < d; i++)
			for (j = 0; j < w; j++)
				scanf("%d", &(matrix[i][j]));
		x = 0;
		alright = 0;
		for (x = 0; x <= k; x++)
		{
			memset(com, 0, sizeof(com));
			memset(checkmatrix, 0, sizeof(checkmatrix));
			dCx(0);
			if (alright == 1)
				break;
		}
		printf("#%d %d\n", temp - t, x);
	}

	return 0;
}