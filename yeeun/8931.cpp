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

			if (n != 0) // 0이 아닐 경우, 스택에 삽입
			{
				s.push(n);
			}
			else // 0일 경우, 맨 위 데이터 삭제
			{	
				if (!s.empty()) // 스택이 비어있지 않으면
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