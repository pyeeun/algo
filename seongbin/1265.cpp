#include <iostream>
using namespace std;

int main()
{
	int t, temp;
	scanf("%d", &t);
	temp = t;
	long long int answer;
	int n, p;
	int low, high;
	int low_times, high_times;
	int i;
	
	while (t--)
	{
		scanf("%d %d", &n, &p);
		answer = 1;

		low = n / p;
		high = n / p + 1;
		low_times = p;
		high_times = 0;

		while (low_times >= 0)
		{
			if (low_times * low + high_times * high == n)
				break;
			low_times--;
			high_times++;
		}

		for (i = 0; i < low_times; i++)
			answer *= low;
		for (i = 0; i < high_times; i++)
			answer *= high;

		printf("#%d %lld\n", temp - t, answer);
	}

	return 0;
}