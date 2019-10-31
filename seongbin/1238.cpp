#include <iostream>
#include <queue>
#include <string.h>
#include <algorithm>
using namespace std;

typedef struct str
{
	int now_where;
	int now_times;
}str;

int matrix[101][101];
int matindex[101];
int visited[101];
queue<str> q;

int main()
{

	int data_length, start;
	int i, j;
	int answer;
	int from, to;
	str s;
	int k;
	int times_max;

	for (i = 0; i < 10; i++)
	{
		memset(matrix, 0, sizeof(matrix));
		memset(matindex, 0, sizeof(matindex));
		memset(visited, 0, sizeof(visited));
		scanf("%d %d", &data_length, &start);
		
		for (j = 0; j < data_length / 2; j++)
		{
			scanf("%d %d", &from, &to);
			matrix[from][matindex[from]++] = to;
		}
		s.now_where = start;
		s.now_times = 1;
		q.push(s);
		
		answer = 0;
		times_max = 1;
		while (!q.empty())
		{
			k = q.front().now_where;
			s.now_times = q.front().now_times + 1;
			for (j = 0; j < matindex[k]; j++)
			{
				if (visited[matrix[k][j]] == 0)
				{
					s.now_where = matrix[k][j];
					q.push(s);
					visited[matrix[k][j]] = 1;
					if (times_max < s.now_times)
					{
						times_max = s.now_times;
						answer = matrix[k][j];
					}
					else if (times_max == s.now_times)
						answer = max(answer, matrix[k][j]);
				}
			}
			q.pop();
		}

		printf("#%d %d\n", i + 1, answer);
	}

	return 0;
}