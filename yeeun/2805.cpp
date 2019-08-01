#include <iostream>
using namespace std;

int main()
{
	int line = 1;
	int t;
	scanf("%d", &t);

	while(t--)
	{
		int map[50][50];
		int n;
		scanf("%d", &n);

		for(int i=0; i<n; i++)
		{
			for(int j=0; j<n; j++)
			{
				scanf("%1d", &map[i][j]);
			}
		}

		int sum = 0;
		int start = n/2, end = n/2;
		int state = 0; // �������� �߰��� ��������

		for(int i=0; i<n; i++)
		{
			for(int j=start; j<=end; j++)
				sum += map[i][j]; // �հ踦 ����

			if(start == 0 && end == n-1)
				state = 1; // �������� �߰� ���� ����

			if(state == 1) // �߰� �Ʒ� ����
			{
				start += 1;
				end -= 1;
			}
			else // �߰� �� ����
			{
				start -= 1;
				end += 1;
			}
		}
		printf("#%d %d\n", line++, sum);
	}
}