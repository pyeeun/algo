#include <iostream>
#include <vector>
#include <math.h>
#include <algorithm>

using namespace std;

typedef struct lotation
{
	int x;
	int y;
}lotation;

vector<lotation> v;

int main()
{
	int t, temp;
	scanf("%d", &t);
	temp = t;
	int n, m;
	int map[20][20];
	int i, j, index;
	int k, answer;
	int sum, num;
	while (t--)
	{
		scanf("%d %d", &n, &m);
		lotation l;
		for (i = 0; i < n; i++)
		{
			for (j = 0; j < n; j++)
			{
				scanf("%d", &(map[i][j]));
				if (map[i][j] == 1)
				{
					l.x = j;
					l.y = i;
					v.push_back(l);
				}
			}
		}

		if (n % 2 == 0)
			k = n + 1;
		else
			k = n;

		answer = 0;

		while (k > 1)
		{
			
			for (i = 0; i < n; i++)
			{
				for (j = 0; j < n; j++)
				{
					sum = 0;
					sum -= k * k + (k - 1)*(k - 1);
					num = 0;
					for (index = 0; index < v.size(); index++)
					{
						if (abs(v[index].x - j) + abs(v[index].y - i) < k)
							num++;
					}
					sum += num * m;
					if (sum >= 0)
					{
						answer = max(answer, num);
					}
				}
			}
			k--;
		}
		if (answer == 0)
			answer = 1;

		printf("#%d %d\n", temp - t, answer);
		v.clear();
	}

	return 0;
}