#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

vector<int> v;
char s[28];
char num[7];
int n, k;

bool compare(int a, int b)
{
	return a > b;
}
int change()
{
	int a = 1;
	int answer = 0;
	int i;
	for (i = n / 4 - 1; i >= 0; i--)
	{
		if (num[i] >= '0' && num[i] <= '9')
		{
			answer += ((int)num[i] - 48)*a;
		}
		else if (num[i] >= 'A' && num[i] <= 'F')
		{
			answer += ((int)num[i] - 55)*a;
		}
		a *= 16;
	}
	return answer;
}

int main()
{
	int t, temp;
	scanf("%d", &t);
	temp = t;
	int answer;
	int i, j;
	
	while (t--)
	{
		scanf("%d %d", &n, &k);
		for (i = 0; i < n; i++)
		{
			scanf("%1c", &(s[i]));
			if (s[i] == '\n')
				i--;
		}

		for (i = 0; i < n; i++)
		{
			for (j = 0; j < n / 4; j++)
			{
				num[j] = s[(i + j) % n];
			}
			v.push_back(change());
		}

		sort(v.begin(), v.end(), compare);
		j = 1;//j번째로 큰 수
		i = 0;//아래서 index
		while (1)
		{
			if (j == k)
				break;
			if (v[i] != v[i + 1])
				j++;
			i++;

		}
		printf("#%d %d\n", temp - t, v[i]);
		v.clear();
	}

	return 0;
}