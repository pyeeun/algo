#include <iostream>
#include <string>
#include <string.h>
#include <algorithm>
using namespace std;

char num[7];
int n;
int answer;

void dfs(int start, int count)
{
	if (count == n)
		answer = max(answer, stoi(num));
	else
	{
		for (int i = start; i < strlen(num); i++)
		{
			for (int j = i + 1; j < strlen(num); j++)
			{
				if (num[j] >= num[i])
				{
					swap(num[i], num[j]);
					dfs(i, count + 1);
					swap(num[i], num[j]);
				}
			}
		}
	}
}
int main()
{
	int t;
	int temp;
	scanf("%d", &t);
	temp = t;
	
	while (t--)
	{
		scanf("%s", num);
		scanf("%d", &n);
		answer = 0;
		dfs(0, 0);
		printf("#%d %d\n", temp - t, answer);
	}
	return 0;
}