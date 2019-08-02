#include <iostream>
#include <algorithm>
#include <math.h>
using namespace std;

int check[10];
int n;
int answer;

int solve(int a)
{
	int ans = 99999999;
	int i = 1;
	int size = 0;
	while (a / i)
	{
		i *= 10;
		size++;
	}
	
	int k = a;
	for (i = 0; i < size; i++)
	{
		if (check[k % 10] == 0)
			break;
		k = k / 10;
	}

	if (i == size)
	{
		return size;
	}
	
	int x, y;
	for (i = 2; i <= sqrt(a); i++)
	{
		if (a % i == 0)
		{
			x = solve(i);
			if (x == 0)
				continue;
			y = solve(a / i);
			if (y == 0)
				continue;
			ans = min(ans, x + y + 1);
		}
	}
	return ans;
}

int main()
{
	int t, temp;
	scanf("%d", &t);
	temp = t;
	int i;

	while (t--)
	{
		answer = 99999999;
		for (i = 0; i < 10; i++)
			scanf("%d", &(check[i]));
		scanf("%d", &n);
		answer = solve(n);
		if (answer == 99999999)
			answer = -1;
		else
			answer++;
		printf("#%d %d\n", temp - t, answer);
	}
	return 0;
}
