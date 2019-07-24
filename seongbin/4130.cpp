#include <iostream>
#include <string.h>
using namespace std;

int main()
{
	int t, temp;
	scanf("%d", &t);
	temp = t;
	int wheel[4][8];
	int top[4];
	int i, j;
	int k;
	int n, turn;
	int left, right;
	int answer;
	int check[4];
	int lr;
	while (t--)
	{
		scanf("%d", &k);
		memset(top, 0, sizeof(top));
		for (i = 0; i < 4; i++)
			for (j = 0; j < 8; j++)
				scanf("%d", &(wheel[i][j]));

		for (j = 0; j < k; j++)
		{
			memset(check, 0, sizeof(check));
			scanf("%d %d", &n, &turn);
			
			check[n - 1] = 1;
			for (i = n - 1; i > 0; i--)//≈È¥œπŸƒ˚ øﬁ¬ ¿∏∑Œ »Æ¿Œ
			{
				left = wheel[i][(top[i] + 6) % 8];
				right = wheel[i - 1][(top[i - 1] + 2) % 8];
				if (left != right)
					check[i - 1] = 1;
				else
					break;
			}
			for (i = n - 1; i < 3; i++)//≈È¥œπŸƒ˚ ø¿∏•¬ ¿∏∑Œ »Æ¿Œ
			{
				right = wheel[i][(top[i] + 2) % 8];
				left = wheel[i + 1][(top[i + 1] + 6) % 8];
				if (left != right)
					check[i + 1] = 1;
				else
					break;
			}
			top[n - 1] = (top[n - 1] + (8 - turn)) % 8;
			lr = -turn;
			for (i = n - 1; i > 0; i--)
			{
				if (check[i - 1] == 1)
				{
					top[i - 1] = (top[i - 1] + (8 - lr)) % 8;
					lr = -lr;
				}
				else
					break;
			}
			lr = -turn;
			for (i = n - 1; i < 3; i++)
			{
				if (check[i + 1] == 1)
				{
					top[i + 1] = (top[i + 1] + (8 - lr)) % 8;
					lr = -lr;
				}
				else
					break;
			}
		}
		answer = wheel[0][top[0]] + 2 * wheel[1][top[1]] + 4 * wheel[2][top[2]] + 8 * wheel[3][top[3]];
		printf("#%d %d\n", temp - t, answer);
	}
	return 0;
}