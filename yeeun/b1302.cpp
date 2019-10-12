#define _CRT_SECURE_NO_WARNINGS
#include <iostream>
#include <vector>
#include <algorithm>
#include <functional>
#include <string>
#include <map>
using namespace std;

int main()
{
	map<string, int> m;
	int n;
	scanf("%d", &n);

	for (int i = 0; i < n; i++)
	{
		string s;
		cin >> s;
		m[s]++;
	}

	int mfreq = 0;
	for (auto i = m.begin(); i != m.end(); i++)
	{
		mfreq = max(mfreq, i->second);
	}

	vector<string> v;
	for (auto i = m.begin(); i != m.end(); i++)
	{
		if ((i->second) == mfreq)
		{
			v.push_back(i->first);
		}
	}

	sort(v.begin(), v.end());
	cout << v[0];
}