#include <iostream>
#include <vector>
#include <algorithm>
#include <string.h>
using namespace std;

int n, m;
long long int k[31]; //주어진 타일로 2^k 최대 몇 개까지 가능한가?
int v[31]; //몇 개 있는가?
int vsize;
int vmax;
bool compare(int a, int b)
{
	return a > b;
}

int math(int i)//2^i 계산
{
	int k = 1;
	for (int j = 0; j < i; j++)
		k *= 2;
	return k;
}

void k_initialize()
{
	long long int l;
	for (int i = 0; i <= vmax; i++)
	{
		if (k[i] != 0)
			continue;
		if (v[i] == 0)
			continue;
		l = (m / math(i));
		k[i] = l * l;
	}
}
int main()
{
	int t, temp;
	scanf("%d", &t);
	temp = t;
	int a, i, j;
	long long int l;
	int answer;
	int num;
	while (t--)
	{
		memset(k, 0, sizeof(k));
		memset(v, 0, sizeof(v));
		answer = 0;
		vmax = 0;
		scanf("%d %d", &n, &m);
		for (i = 0; i < n; i++)
		{
			scanf("%d", &a);
			v[a]++;
			vmax = max(vmax, a);
		}
		num = 0;
		vsize = n;
		i = vmax;
		k_initialize();
		while (num < n)
		{
			if (k[i] == 0)
				;
			else if (k[i] < v[i])
			{
				for (j = i - 1; j >= 0; j--)
				{
					if (v[j] == 0)
						continue;
					l = math(i - j);
					k[j] -= l * l * k[i];
				}
				num += k[i];
				v[i] -= k[i];
				k[i] -= k[i];
			}
			else
			{
				for (j = i - 1; j >= 0; j--)
				{
					if (v[j] == 0)
						continue;
					l = math(i - j);
					k[j] -= l * l * v[i];
				}
				num += v[i];
				k[i] -= v[i];
				v[i] -= v[i];
			}

			while (--i >= 0 && v[i] == 0)
				;

			if (i == -1)
			{
				i = vmax + 1;
				while (--i >= 0 && v[i] == 0)
					;
				vmax = i;
				memset(k, 0, sizeof(k));
				k_initialize();
				answer++;
			}
		}
		printf("#%d %d\n", temp - t, answer);
	}
	return 0;
}