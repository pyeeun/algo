#include <iostream>
#include <string.h>
using namespace std;

int main()
{
	int t;
	int n, m;
	scanf("%d", &t);
	char matrix[50][100];
	char code[8];
	code[7] = '\0';
	int i, j;
	int x, y;
	int sum;
	char _0[8] = "0001101";
	char _1[8] = "0011001";
	char _2[8] = "0010011";
	char _3[8] = "0111101";
	char _4[8] = "0100011";
	char _5[8] = "0110001";
	char _6[8] = "0101111";
	char _7[8] = "0111011";
	char _8[8] = "0110111";
	char _9[8] = "0001011";
	int number;
	int checkcode = 0;
	int temp = t;
	while (t--)
	{
		scanf("%d %d", &n, &m);
		sum = 0;
		checkcode = 0;

		for (i = 0; i < n; i++)
		{
			for (j = 0; j < m; j++)
			{
				scanf("%c", &(matrix[i][j]));
				if (matrix[i][j] == '1')
				{
					y = i;
					x = j;
				}
				if (matrix[i][j] == '\n')
					j--;
			}
		}

		for (i = 0; i < 8; i++)
		{
			for (j = 0; j < 7; j++)
			{
				code[6 - j] = matrix[y][x];
				x--;
				if (x < 0)
				{
					x = m - 1;
					y--;
				}
			}

			if (strcmp(_0, code) == 0)
			{
				number = 0;
			}
			else if (strcmp(_1, code) == 0)
			{
				number = 1;
			}
			else if (strcmp(_2, code) == 0)
			{
				number = 2;
			}
			else if (strcmp(_3, code) == 0)
			{
				number = 3;
			}
			else if (strcmp(_4, code) == 0)
			{
				number = 4;
			}
			else if (strcmp(_5, code) == 0)
			{
				number = 5;
			}
			else if (strcmp(_6, code) == 0)
			{
				number = 6;
			}
			else if (strcmp(_7, code) == 0)
			{
				number = 7;
			}
			else if (strcmp(_8, code) == 0)
			{
				number = 8;
			}
			else if (strcmp(_9, code) == 0)
			{
				number = 9;
			}

			sum += number;
			if (i % 2 == 1)
				checkcode += number * 3;
			else
				checkcode += number;
		}

		if (checkcode % 10 == 0)
			printf("#%d %d\n", temp - t, sum);
		else
			printf("#%d 0\n", temp - t);
	}
	return 0;
}