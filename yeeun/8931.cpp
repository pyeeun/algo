#define _CRT_SECURE_NO_WARNINGS
#include <iostream>
#include <stack>
using namespace std;

int main()
{
	int line = 1;
	int t;
	scanf("%d", &t);

	while (t--)
	{
		stack<int> s;
		int k;
		scanf("%d", &k);

		int n;
		for (int i = 0; i < k; i++)
		{
			scanf("%d", &n);

			if (n != 0) // 0�� �ƴ� ���, ���ÿ� ����
			{
				s.push(n);
			}
			else // 0�� ���, �� �� ������ ����
			{	
				if (!s.empty()) // ������ ������� ������
					s.pop();
			}
		}

		int res = 0;
		while (!s.empty())
		{
			res += s.top();
			s.pop();
		}

		printf("#%d %d\n", line++, res);
	}
}