#include <iostream>
#include <string.h>
using namespace std;

int main()
{
	int t;
	int n;
	int score[101];
	int max;
	int i;
	int x;
	int maxnum;
	scanf("%d", &t);
	while (t--)
	{
		max = 0;
		maxnum = 0;
		memset(score, 0, sizeof(score));
		scanf("%d", &n);
		for (i = 0; i < 1000; i++)
		{
			scanf("%d", &x);
			score[x]++;
			if (max < score[x])
			{
				max = score[x];
				maxnum = x;
			}
			else if (max == score[x])
				if (maxnum < x)
					maxnum = x;
		}
		printf("#%d %d\n", n, maxnum);
	}
	return 0;
}