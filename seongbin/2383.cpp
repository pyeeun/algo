#include <iostream>
#include <vector>
#include <math.h>
#include <algorithm>
using namespace std;

typedef struct location
{
	int x;
	int y;
}location;

vector<location> people;
vector<location> stairs;
vector<int> first;
vector<int> second;
int test_case[10];
int answer;
int first_num, second_num;

bool compare(int a, int b)
{
	return a > b;
}

void solve()
{

	int i;
	int a;
	for (i = 0; i < people.size(); i++)
	{
		if (test_case[i] == 0)
		{
			first.push_back(abs(stairs[0].x - people[i].x) + abs(stairs[0].y - people[i].y));
		}
		else if (test_case[i] == 1)
		{
			second.push_back(abs(stairs[1].x - people[i].x) + abs(stairs[1].y - people[i].y));
		}
	}
	
	sort(first.begin(), first.end());
	sort(second.begin(), second.end());

	int f = 0, s = 0;
	vector<int> vtemp;
	int index = 0;
	//first 계산
	while (index < first.size())
	{
		if (vtemp.size() != 0)
		{
			sort(vtemp.begin(), vtemp.end(), compare);
			i = vtemp.size() - 1;
			while (i >= 0)
			{
				if (f == vtemp[i] + first_num)
					vtemp.pop_back();
				i--;
			}
		}

		if (first[index] + 1 <= f && vtemp.size() < 3)
		{
			vtemp.push_back(f);
			f--;
			index++;
		}
		f++;
	}
	if (vtemp.size() != 0)
	{
		sort(vtemp.begin(), vtemp.end(), compare);
		f = vtemp[0] + first_num;
	}
	vtemp.clear();
	index = 0;
	//second 계산
	while (index < second.size())
	{
		if (vtemp.size() != 0)
		{
			sort(vtemp.begin(), vtemp.end(), compare);
			i = vtemp.size() - 1;
			while (i >= 0)
			{
				if (s == vtemp[i] + second_num)
					vtemp.pop_back();
				i--;
			}
		}

		if (second[index] + 1 <= s && vtemp.size() < 3)
		{
			vtemp.push_back(s);
			s--;
			index++;
		}
		s++;
	}
	if (vtemp.size() != 0)
	{
		sort(vtemp.begin(), vtemp.end(), compare);
		s = vtemp[0] + second_num;
	}


	a = max(f, s);
	answer = min(answer, a);
	first.clear();
	second.clear();
	vtemp.clear();
}

void make_case(int i)
{
	test_case[i] = 0;
	if (i == people.size() - 1)
		solve();
	else
		make_case(i + 1);

	test_case[i] = 1;
	if (i == people.size() - 1)
		solve();
	else
		make_case(i + 1);
}

int main()
{
	int t, temp;
	scanf("%d", &t);
	temp = t;
	int n;
	int i, j;
	int a;
	while (t--)
	{
		first_num = 0, second_num = 0;
		scanf("%d", &n);
		for (i = 0; i < n; i++)
		{
			for (j = 0; j < n; j++)
			{
				scanf("%d", &a);
				if (a == 0)
					continue;
				else if (a == 1)
				{
					location l;
					l.x = j;
					l.y = i;
					people.push_back(l);
				}
				else
				{
					location l;
					l.x = j;
					l.y = i;
					stairs.push_back(l);
					if (first_num == 0)
						first_num = a;
					else
						second_num = a;
				}
			}
		}

		answer = 99999999;
		make_case(0);

		printf("#%d %d\n", temp - t, answer);
		stairs.clear();
		people.clear();
	}

	return 0;
}