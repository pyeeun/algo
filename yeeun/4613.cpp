#include <iostream>
#include <cstring>
using namespace std;

int main()
{
	int line = 1;
	int t; // �׽�Ʈ ���̽��� ��
	scanf("%d", &t);

	while(t--)
	{
		int color[51][3];
		int n,m; // ���� ����
		scanf("%d %d", &n, &m);

		for(int i=0; i<n; i++)
		{
			int white = 0, blue = 0, red = 0; // ���� ��

			for(int j=0; j<m; j++)
			{
				char color;
				scanf(" %c", &color); // ����ڷκ��� ���� �Է¹���

				if(color == 'W') // White
 					white++;
				else if(color == 'B') // Blue
					blue++;
				else if(color == 'R') // Red
					red++;
			}

			// �Ѱ��� ������ ä�� ���, �ٲ�� �ϴ� ���� ��
			color[i][0] = m - white; // ���(W)���� ä�� ��, (B+R)
			color[i][1] = m - blue; // �Ķ���(B)���� ä�� ��, (W+R)
			color[i][2] = m - red; // ������(R)���� ä�� ��, (W+B)
		}

		int min_cnt = 9876543; // �ּ� ���� ��

		// �� ������ �ּ� 1�� �̻� ĥ�������ϹǷ�
		// white�� ĥ���� �� �ִ� �ִ� ������ n-2
		// w : white, b : blue, r : red
		for(int w=1; w<=n-2; w++)
		{
			for(int b=1; b<n; b++)
			{
				int cnt = 0; // �� �ٲ���ϴ� ������ ��
				int r = n - (w+b); // W�� B�� ������ R�� ����

				// White �ٷ� ä���� �� �ٲ�� �ϴ� ������ ��
				// 0��° �ٺ��� ä��
				for(int l=0; l<w; l++)
					cnt += color[l][0];
				
				// Blue �ٷ� ä���� �� �ٲ�� �ϴ� ������ ��
				// White �� ���ĺ��� ä���� ��
				for(int l=w; l<w+b; l++)
					cnt += color[l][1];
				
				// Red �ٷ� ä���� �� �ٲ�� �ϴ� ������ ��
				// White + Blue�� ���ĺ��� ä��
				for(int l=w+b; l<w+b+r; l++)
					cnt += color[l][2];

				min_cnt = min(min_cnt,cnt); // �ּ� ���� ����

				if(r <= 1) // k(Red)�� 1�� ���ϰ� �� ���, break (�ּ� 1�� �̻�)
					break;
			}
		}
		printf("#%d %d\n", line++, min_cnt);
	}
}