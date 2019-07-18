#include <iostream>
#include <algorithm>
#include <string.h>
using namespace std;


int main()
{
	int t;
	int temp;
	scanf("%d", &t);
	temp = t;
	int n, x;
	int i, j;
	int matrix[20][20];
	int nowheight;
	int nowtimes;
	int check;
	int answer;
	while (t--)
	{
		scanf("%d %d", &n, &x);
		answer = 0;
		for (i = 0; i < n; i++)
		{
			for (j = 0; j < n; j++)
			{
				scanf("%d", &(matrix[i][j]));
			}
			nowheight = matrix[i][0];
			nowtimes = 0;
			check = 0;
			for (j = 0; j < n - 1; j++)
			{
				nowtimes++;
				if (check == 1 && nowtimes == x)
				{
					check = 0;
					nowtimes = 0;
				}

				if (matrix[i][j] > matrix[i][j + 1])
				{
					if (matrix[i][j] != matrix[i][j + 1] + 1)
						break;
					if (j == n - 2)
					{
						nowtimes = 0;
						break;
					}
					if (check == 0)
					{
						nowtimes = 0;
						check = 1;
					}
					else
					{
						if (nowtimes < x)
						{
							nowtimes = 0;
							break;
						}
						nowtimes = 0;
					}
				}
				else if (matrix[i][j] == matrix[i][j + 1])
				{
					continue;
				}
				else
				{
					if (matrix[i][j] + 1 != matrix[i][j + 1])
						break;
					if (nowtimes < x)
						break;
					nowtimes = 0;
					check = 0;
				}
			}
			nowtimes++;
			if (j == n - 1)
			{
				if (check == 1 && nowtimes < x)
					;
				else
					answer++;
			}
		}
		
		for (j = 0; j < n; j++)
		{
			nowheight = matrix[0][j];
			nowtimes = 0;
			check = 0;
			for (i = 0; i < n - 1; i++)
			{
				nowtimes++;
				if (check == 1 && nowtimes == x)
				{
					check = 0;
					nowtimes = 0;
				}
				if (matrix[i][j] > matrix[i + 1][j])
				{
					if (matrix[i][j] != matrix[i + 1][j] + 1)
						break;
					if (i == n - 2)
					{
						nowtimes = 0;
						break;
					}
					if (check == 0)
					{
						check = 1;
						nowtimes = 0;
					}
					else
					{
						if (nowtimes < x)
						{
							nowtimes = 0;
							break;
						}
						nowtimes = 0;
					}
				}
				else if (matrix[i][j] == matrix[i + 1][j])
				{
					continue;
				}
				else
				{
					if (matrix[i][j] + 1 != matrix[i + 1][j])
						break;
					if (nowtimes < x)
						break;

					nowtimes = 0;
					check = 0;
				}
			}
			nowtimes++;
			if (i == n - 1)
			{
				if (check == 1 && nowtimes < x)
					;
				else
					answer++;
			}
		}
		printf("#%d %d\n", temp - t, answer);
	}
	return 0;
}