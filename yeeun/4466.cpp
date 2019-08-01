#include <iostream>
#include <algorithm>
#include <vector>
using namespace std;

int main()
{
	int t;
	int line = 1;
	scanf("%d", &t);

	while(t--)
	{
		vector<int> v;
		int n,k;
		scanf("%d %d", &n, &k);

		for(int i=0; i<n; i++)
		{
			int num;
			scanf("%d", &num);
			v.push_back(num);
		}

		sort(v.begin(), v.end(), greater<int>());
		
		int sum = 0;
		for(int i=0; i<k; i++)
			sum += v[i];

		printf("#%d %d\n", line++, sum);
	}
}