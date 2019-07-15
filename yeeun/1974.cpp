#include <iostream>
using namespace std;

int main()
{
	int t;
	int line = 1;
	int map[10][10];
	int w_check[10][10]; // 가로줄 체크
	int h_check[10][10]; // 세로줄 체크
	int s_check[10][10]; // 사각형 체크

	scanf("%d", &t);

	while(t--)
	{
		memset(map, 0, sizeof(map));
		memset(w_check, 0, sizeof(w_check));
		memset(h_check, 0, sizeof(h_check));
		memset(s_check, 0, sizeof(s_check));

		for(int i=1; i<10; i++)
			for(int j=1; j<10; j++)
				scanf("%d", &map[i][j]);
		
		// 가로 & 세로 방향에 대해서 중복 값이 있는지
		// 카운트를 세어서 체크
		for(int l=1; l<10; l++)
		{
			for(int w=1; w<10; w++)
			{
				int value = map[l][w];
				w_check[l][value] += 1;
			}

			for(int h=1; h<10; h++)
			{
				int value = map[h][l];
				h_check[value][l] += 1;
			}
		}

		// 사각형도 가로&세로와 마찬가지로 체크
		int l = 1;
		for(int i=1; i<10; i+=3)
		{
			for(int j=1; j<10; j+=3)
			{
				for(int x=0; x<3; x++)
				{
					for(int y=0; y<3; y++)
					{
						int value = map[x+i][j+y];
						s_check[l][value] += 1;
					}
				}
				l += 1; // 사각형 카운트
			}
		}

		int result = 1;
		// 중복 체크
		for(int i=1; i<10; i++)
		{
			for(int j=1; j<10; j++)
			{
				// 하나라도 중복되는 값이 존재한다면
				if(w_check[i][j] != 1 || h_check[i][j] != 1 || s_check[i][j] != 1)
					result = 0;
			}
		}

		printf("#%d %d\n", line++, result);
	}
}