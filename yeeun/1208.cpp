#include <iostream>
#include <vector>
#include <algorithm>
#include <cstring>
using namespace std;

int main()
{
	int t = 10;
	int line = 1;

	while(t--)
	{
		int dump;
		scanf("%d", &dump);

		vector<int> v;
		for(int i=0; i<100; i++)
		{
			int height;
			scanf("%d", &height);
			v.push_back(height);
		}

		while(dump--)
		{
			// ���� ������ ���� �� ��źȭ �۾�
			sort(v.begin(), v.end());
			v[0] = v[0]+1;
			v[99] = v[99]-1;
		}

		// ���� �� ���� ����
		// ���� ���� ������ ���� ������ ���� ����
		sort(v.begin(), v.end());
		int result = v[99] - v[0];

		printf("#%d %d\n", line++, result);
	}
}