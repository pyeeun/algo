#include <iostream>
#include <string.h>
using namespace std;

int main()
{
	int t, temp;
	int v, e, v1, v2;
	scanf("%d", &t);
	temp = t;
	int a, b;
	int i;
	int parent[10001];
	int check[10001];
	int answer;
	int k;

	while (t--)
	{
		scanf("%d %d %d %d", &v, &e, &v1, &v2);
		memset(parent, 0, sizeof(parent));
		memset(check, 0, sizeof(check));
		answer = 0;

		for (i = 0; i < e; i++)
		{
			scanf("%d %d", &a, &b);
			parent[b] = a;
		}

		int now = v1;

		while (1)
		{
			if (parent[v1] == 1)
			{
				check[1] = 1;
				break;
			}
			check[parent[v1]] = 1;
			v1 = parent[v1];
		}

		while (1)
		{
			if (check[v2] == 1)
				break;
			v2 = parent[v2];
		}

		for (i = 1; i <= v; i++)
		{
			k = i;
			while (1)
			{
				if (parent[k] == v2 || k == v2)
				{
					answer++;
					break;
				}
				else if (parent[k] == 1 || parent[k] == 0)
					break;
				else
					k = parent[k];
			}
		}
		printf("#%d %d %d\n", temp - t, v2, answer);
	}
	return 0;
}