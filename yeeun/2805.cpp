#include <iostream>
using namespace std;

int main()
{
	int line = 1;
	int t;
	scanf("%d", &t);

	while(t--)
	{
		int map[50][50];
		int n;
		scanf("%d", &n);

		for(int i=0; i<n; i++)
		{
			for(int j=0; j<n; j++)
			{
				scanf("%1d", &map[i][j]);
			}
		}

		int sum = 0;
		int start = n/2, end = n/2;
		int state = 0; // 마름모의 중간을 지났는지

		for(int i=0; i<n; i++)
		{
			for(int j=start; j<=end; j++)
				sum += map[i][j]; // 합계를 구함

			if(start == 0 && end == n-1)
				state = 1; // 마름모의 중간 줄을 지남

			if(state == 1) // 중간 아래 구간
			{
				start += 1;
				end -= 1;
			}
			else // 중간 위 구간
			{
				start -= 1;
				end += 1;
			}
		}
		printf("#%d %d\n", line++, sum);
	}
}