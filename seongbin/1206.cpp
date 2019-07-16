#include <iostream>
#include <algorithm>
using namespace std;

int main()
{
	int t;
	int answer;
	int n;
	int apart[1000];
	int i;
	for (t = 0; t < 10; t++)
	{
		answer = 0;
		scanf("%d", &n);
		for (i = 0; i < n; i++)
			scanf("%d", &(apart[i]));

		for (i = 2; i < n - 2; i++)
		{
			if (apart[i] > max(max(apart[i - 1], apart[i - 2]), max(apart[i + 1], apart[i + 2])))
			{
				answer += apart[i] - max(max(apart[i - 1], apart[i - 2]), max(apart[i + 1], apart[i + 2]));
			}
		}
		printf("#%d %d\n", t + 1, answer);
	}
	return 0;
}