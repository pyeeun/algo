#include <iostream>
#include <string.h>

using namespace std;

int main()
{
	int matrix[101][101];
	int t = 10;
	int n;
	int sum, max;
	int i, j;
	while (t--)
	{
		scanf("%d", &n);
		sum = 0;
		max = 0;

		for (i = 1; i <= 100; i++)
		{
			sum = 0;
			for (j = 1; j <= 100; j++)
			{
				scanf("%d", &(matrix[i][j]));
				sum += matrix[i][j];
			}
			if (sum > max)
				max = sum;
		}

		for (j = 1; j <= 100; j++)
		{
			sum = 0;
			for (i = 1; i <= 100; i++)
			{
				sum += matrix[i][j];
			}
			if (sum > max)
				max = sum;
		}
		
		//오른쪽 아래 대각선
		sum = 0;
		for (i = 1; i <= 100; i++)
		{
			sum += matrix[i][i];
		}
		if (sum > max)
			max = sum;

		//왼쪽 아래 대각선
		sum = 0;
		for (i = 1; i <= 100; i++)
		{
			sum += matrix[i][101 - i];
		}
		if (sum > max)
			max = sum;

		printf("#%d %d\n", n, max);
	}
	return 0;
}