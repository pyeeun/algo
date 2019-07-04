#include <iostream>
#include <cstring>
using namespace std;

int main()
{
	int line = 1;
	int t; // 테스트 케이스의 수
	scanf("%d", &t);

	while(t--)
	{
		int color[51][3];
		int n,m; // 세로 가로
		scanf("%d %d", &n, &m);

		for(int i=0; i<n; i++)
		{
			int white = 0, blue = 0, red = 0; // 색상 수

			for(int j=0; j<m; j++)
			{
				char color;
				scanf(" %c", &color); // 사용자로부터 색상 입력받음

				if(color == 'W') // White
 					white++;
				else if(color == 'B') // Blue
					blue++;
				else if(color == 'R') // Red
					red++;
			}

			// 한가지 색으로 채울 경우, 바꿔야 하는 색상 수
			color[i][0] = m - white; // 흰색(W)으로 채울 때, (B+R)
			color[i][1] = m - blue; // 파란색(B)으로 채울 때, (W+R)
			color[i][2] = m - red; // 빨간색(R)으로 채울 때, (W+B)
		}

		int min_cnt = 9876543; // 최소 색상 수

		// 각 색상은 최소 1줄 이상 칠해져야하므로
		// white가 칠해질 수 있는 최대 개수는 n-2
		// w : white, b : blue, r : red
		for(int w=1; w<=n-2; w++)
		{
			for(int b=1; b<n; b++)
			{
				int cnt = 0; // 총 바꿔야하는 색상의 수
				int r = n - (w+b); // W와 B를 제외한 R의 개수

				// White 줄로 채웠을 때 바꿔야 하는 색상의 수
				// 0번째 줄부터 채움
				for(int l=0; l<w; l++)
					cnt += color[l][0];
				
				// Blue 줄로 채웠을 때 바꿔야 하는 색상의 수
				// White 줄 이후부터 채워야 함
				for(int l=w; l<w+b; l++)
					cnt += color[l][1];
				
				// Red 줄로 채웠을 때 바꿔야 하는 색상의 수
				// White + Blue줄 이후부터 채움
				for(int l=w+b; l<w+b+r; l++)
					cnt += color[l][2];

				min_cnt = min(min_cnt,cnt); // 최소 값을 구함

				if(r <= 1) // k(Red)가 1줄 이하가 될 경우, break (최소 1줄 이상)
					break;
			}
		}
		printf("#%d %d\n", line++, min_cnt);
	}
}