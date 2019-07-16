#include <iostream>
#include <string.h>
using namespace std;

int main()
{
	int answer;
	int t;
	scanf("%d", &t);
	int temp = t;
	int matrix[10][10];
	int i, j;
	int num[10] = { 0 };
	int x, y;

	while (t--)
	{
		answer = 1;
		memset(num, 0, sizeof(num));
		for (i = 1; i <= 9; i++)
		{
			for (j = 1; j <= 9; j++)
			{
				scanf("%d", &(matrix[i][j]));
				num[matrix[i][j]]++;
			}
			
			for (j = 1; j < 9; j++)
			{
				if (num[j] != num[j + 1]) //가로 확인
					answer = 0;
			}
		}

		memset(num, 0, sizeof(num));
		for (j = 1; j <= 9; j++)
		{
			for (i = 1; i <= 9; i++)
			{
				num[matrix[i][j]]++;
			}
				
			for (i = 1; i < 9; i++)
			{
				if (num[i] != num[i + 1]) //세로 확인
					answer = 0;
			}
		}

		memset(num, 0, sizeof(num));

		for (i = 1; i <= 7; i += 3)
		{
			for (j = 1; j <= 7; j += 3)
			{
				for (x = j; x < j + 3; x++)
					for (y = i; y < i + 3; y++)
						num[matrix[y][x]]++;

				for (x = 1; x < 9; x++)
					if (num[x] != num[x + 1])
						answer = 0;
			}
		}

		printf("#%d %d\n", temp - t, answer);
	}
	return 0;
}