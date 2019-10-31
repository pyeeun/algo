#include <iostream>
#include <queue>
#include <string.h>
using namespace std;

queue<int> q;

int main()
{
	int t, n;
	int road1[100];
	int road2[100];
	int start, end;
	int i;
	int answer;
	int now;
	int visited[100];
	for (t = 1; t <= 10; t++)
	{
		scanf("%d %d", &t, &n);
		memset(road1, -1, sizeof(road1));
		memset(road2, -1, sizeof(road2));
		memset(visited, 0, sizeof(visited));
		answer = 1;

		for (i = 0; i < n; i++)
		{
			scanf("%d %d", &start, &end);
			if (road1[start] == -1)
				road1[start] = end;
			else
				road2[start] = end;
		}

		q.push(0);

		while (!q.empty())
		{
			now = q.front();
			if (road1[now] != -1)
			{
				if (visited[road1[now]] == 0)
				{
					q.push(road1[now]);
					visited[road1[now]] = 1;
				}
				
				if (road2[now] != -1 && visited[road2[now]] == 0)
				{
					q.push(road2[now]);
					visited[road2[now]] = 1;
				}
			}
			q.pop();
		}

		if (visited[99]==0)
			answer = 0;

		printf("#%d %d\n", t, answer);

	}
	return 0;
}