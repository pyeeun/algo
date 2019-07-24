#include <iostream>
#include <cstring>
#include <algorithm>
using namespace std;

int t;
int k;
int line = 1;
int wheel[4][8];

void moveWheel(int n, int dir)
{
	int start = wheel[n][0]; // ó���� �ӽ� ����
	int end = wheel[n][7]; // �������� �ӽ� ����
	memmove(wheel[n], wheel[n]-dir, sizeof(wheel[n])); // dir(1:�ð�,-1:�ݽð�)
	
	if(dir == 1) // �ð�����̾��� ���, 0��° �迭�� �� ����
		wheel[n][0] = end;
	else if(dir == -1) // �ݽð�����̾��� ���, 7��° �迭�� �� ����
		wheel[n][7] = start;
}

int main()
{
	scanf("%d", &t);

	while(t--)
	{
		memset(wheel, 0, sizeof(wheel));
		scanf("%d", &k);

		for(int i=0; i<4; i++)
			for(int j=0; j<8; j++)
				scanf("%d", &wheel[i][j]);

		for(int i=0; i<k; i++)
		{
			int n; // ȸ����ų ������ ��ȣ
			int dir; // ȸ����ų ����(1:�ð�,2:�ݽð�)
			scanf("%d %d", &n, &dir);

			bool w12 = wheel[0][2] != wheel[1][6] ? true : false; // 1,2��° ���� ȸ�� ����
			bool w23 = wheel[1][2] != wheel[2][6] ? true : false; // 2,3��° ���� ȸ�� ����
			bool w34 = wheel[2][2] != wheel[3][6] ? true : false; // 3,4��° ���� ȸ�� ����

			moveWheel(n-1, dir); // �ڱ� �ڽ� ȸ��

			if(n == 1) // ������ ���� ������ ���ؼ� ȸ��
			{
				if(w12 == true) // �ι�° ���� ȸ��
				{
					moveWheel(1, -dir);

					if(w23 == true) // ����° ���� ȸ��
					{
						moveWheel(2, dir);

						if(w34 == true) // �׹�° ���� ȸ��
							moveWheel(3, -dir);
					}
				}
			}

			if(n == 2) // �ι�° ������ ���
			{
				if(w12 == true)
					moveWheel(0, -dir); // ù��° ���� ȸ��
				if(w23 == true)
				{
					moveWheel(2, -dir); // ����° ���� ȸ��
					if(w34 == true)
						moveWheel(3,dir); // �׹�° ���� ȸ��
				}
			}

			if(n == 3)
			{
				if(w23 == true)
				{
					moveWheel(1, -dir); // �ι�° ���� ȸ��
					if(w12 == true)
						moveWheel(0, dir); // ù��° ���� ȸ��
				}
				if(w34 == true)
					moveWheel(3, -dir); // �׹�° ���� ȸ��
			}

			if(n == 4) // ������ ������ ���, ���� �����鿡 ���� ȸ��
			{
				if(w34 == true)
				{
					moveWheel(2, -dir); // ����° ���� ȸ��
					if(w23 == true)
					{
						moveWheel(1,dir); // �ι�° ���� ȸ��
						if(w12 == true)
							moveWheel(0,-dir); // ù��° ���� ȸ��
					}
				}
			}
		}

		int score = 0;
		for(int i=0; i<4; i++)
		{
			if(wheel[i][0] == 1) // S���� ���, ���� �߰�
				score += (int)pow(2.0,i);
		}
		printf("#%d %d\n", line++, score);
	}
}

