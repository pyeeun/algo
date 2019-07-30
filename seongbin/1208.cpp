#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;
vector<int> box;
int main()
{
	int t;
	int n;
	int i, a;
	int maxnum = 0, minnum = 1000;
	int left, right, mid;
	int answermax, answermin, answer;
	for (t = 1; t <= 10; t++)
	{
		maxnum = 0, minnum = 1000;
		scanf("%d", &n);
		for (i = 0; i < 100; i++)
		{
			scanf("%d", &a);
			maxnum = max(maxnum, a);
			minnum = min(minnum, a);
			box.push_back(a);
		}
		sort(box.begin(), box.end());
		left = minnum, right = maxnum;
		
		while (left <= right)
		{
			a = 0;
			mid = (left + right) / 2;
			for (i = box.size() - 1; i >= 0; i--)
			{
				if (box[i] > mid)
					a += (box[i] - mid);
				else
					break;
			}
			if (a > n)
				left = mid + 1;
			else if (a < n)
			{
				answer = mid;
				right = mid - 1;
			}
			else
			{
				answer = mid;
				break;
			}
		}
		answermax = answer;
		
		left = minnum, right = maxnum;
		
		while (left <= right)
		{
			a = 0;
			mid = (left + right) / 2;
			for (i = 0; i < box.size(); i++)
			{
				if (box[i] < mid)
					a += (mid - box[i]);
				else
					break;
			}
			if (a > n)
				right = mid - 1;
			else if (a < n)
			{
				left = mid + 1;
				answer = mid;
			}
			else
			{
				answer = mid;
				break;
			}
		}
		answermin = answer;
		printf("#%d %d\n", t, answermax - answermin);
		box.clear();
	}
	return 0;
}