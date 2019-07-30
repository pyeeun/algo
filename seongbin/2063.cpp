#include <iostream>
#include <algorithm>
#include <vector>
using namespace std;

vector<int> v;

int main()
{
	int n;
	int a;
	scanf("%d", &n);
	for (int i = 0; i < n; i++)
	{
		scanf("%d", &a);
		v.push_back(a);
	}
	sort(v.begin(), v.end());
	printf("%d", v[v.size() / 2]);
	return 0;
}