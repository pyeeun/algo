#include <iostream>
#include <string.h>
using namespace std;

typedef struct stick
{
	int start;
	int end;
}stick;

int main()
{
	int t, temp;
	int n;
	scanf("%d", &t);
	temp = t;
	int i;
	stick s[20];
	int check1[31];
	int check2[31];
	int start, end, now;
	while (t--)
	{
		memset(check1, 0, sizeof(check1));
		memset(check2, 0, sizeof(check2));
		scanf("%d", &n);
		for (i = 0; i < n; i++)
		{
			scanf("%d %d", &(s[i].start), &(s[i].end));
			check1[s[i].start] = 1;
			check2[s[i].end] = 1;
		}
		for (i = 0; i < 31; i++)
		{
			if (check1[i] == 1 && check2[i] == 0)
				start = i;
			else if (check1[i] == 0 && check2[i] == 1)
				end = i;
		}
		now = start;
		printf("#%d ", temp - t);
		while (now != end)
		{
			for (i = 0; i < 31; i++)
			{
				if (s[i].start == now)
				{
					printf("%d %d ", s[i].start, s[i].end);
					now = s[i].end;
					break;
				}
			}
		}
		printf("\n");
	}

	return 0;
}