#include <iostream>
#include <cstring>
using namespace std;

int main()
{
	int apt[1010];
	int t = 10;
	int line = 1;
	
	while(t--)
	{
		memset(apt, 0, sizeof(apt));

		int width;
		scanf("%d", &width);

		int view = 0; // �������� Ȯ���� ����Ʈ�� ��

		for(int i=2; i<width+2; i++) // ���� ��ĭ�� �����ä�� �迭�� ���� 
			scanf("%d", &apt[i]);

		for(int w=2; w<width+2; w++)
		{
			int cur_width = apt[w]; // ���� ����Ʈ�� ����
			int left = w-2; // ���ʹ������� üũ�� ����
			int right = w+2; // �����ʹ������� üũ�� ����

			// ���� �������� ���� Ž��
			int leftview = 1, leftheight = -1;
			for(int i=w-1; i>=left; i--)
			{
				if(apt[w] < apt[i]) // ���� ����Ʈ���� �� ���� ��� �ߴ�
				{
					leftview = 0;
					break;
				}
				else
				{
					// ���� ������ 2ĭ ���ʿ� �ִ� ���� ���� ������ ���� �� ����
					if(leftheight == -1) // ù��° ���� ���, ù��° ���� �־���
						leftheight = apt[w] - apt[i];
					else // �ι�° ���� ���, �� ���̰� ���� ���� ��(���� ���� �켱)
						leftheight = min(leftheight, apt[w] - apt[i]);
				}
			}

			// ������ �������� ���� Ž��
			int rightview = 1, rightheight = -1;
			for(int i=w+1; i<=right; i++)
			{
				if(apt[w] <= apt[i]) // ���� ����Ʈ���� �� ���� ��� �ߴ�
				{
					rightview = 0;
					break;
				}
				else
				{
					// ���� ������ 2ĭ ���ʿ� �ִ� ���� ���� ������ ���� �� ����
					if(rightheight == -1) // ù��° ���� ���, ù��° ���� �־���
						rightheight = apt[w] - apt[i];
					else // �ι�° ���� ���, �� ���̰� ���� ���� ��(���� ���� �켱)
						rightheight = min(rightheight, apt[w] - apt[i]);
				}
			}

			// �¿� ��� �������� Ȯ������ ���, ������ ���� 1 ����
			if(leftview == 1 && rightview == 1)
			{
				view = view + min(leftheight, rightheight);
			}
		}
		printf("#%d %d\n", line++, view);
	}
}