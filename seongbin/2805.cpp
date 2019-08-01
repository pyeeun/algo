#include <iostream>
#include <algorithm>
using namespace std;

int main()
{
	int t, temp;
	scanf("%d", &t);
	temp = t;
	int n;
	int matrix[49][49];
	int start, end;
	int i, j;
	int check;
	int answer;
	while (t--)
	{
		scanf("%d", &n);
		for (i = 0; i < n; i++)
			for (j = 0; j < n; j++)
				scanf("%1d", &(matrix[i][j]));

		start = n / 2, end = n / 2;
		check = 0;
		answer = 0;

		for (i = 0; i < n; i++)
		{
			for (j = start; j <= end; j++)
			{
				answer += matrix[i][j];
			}
			if (check == 0)
			{
				start--;
				end++;
				if (start == 0)
					check = 1;
			}
			else if (check == 1)
			{
				start++;
				end--;
			}
		}
		printf("#%d %d\n", temp - t, answer);
	}
	return 0;
}