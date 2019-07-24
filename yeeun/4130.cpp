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
	int start = wheel[n][0]; // 처음값 임시 저장
	int end = wheel[n][7]; // 마지막값 임시 저장
	memmove(wheel[n], wheel[n]-dir, sizeof(wheel[n])); // dir(1:시계,-1:반시계)
	
	if(dir == 1) // 시계방향이었을 경우, 0번째 배열에 값 삽입
		wheel[n][0] = end;
	else if(dir == -1) // 반시계방향이었을 경우, 7번째 배열에 값 삽입
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
			int n; // 회전시킬 바퀴의 번호
			int dir; // 회전시킬 방향(1:시계,2:반시계)
			scanf("%d %d", &n, &dir);

			bool w12 = wheel[0][2] != wheel[1][6] ? true : false; // 1,2번째 바퀴 회전 여부
			bool w23 = wheel[1][2] != wheel[2][6] ? true : false; // 2,3번째 바퀴 회전 여부
			bool w34 = wheel[2][2] != wheel[3][6] ? true : false; // 3,4번째 바퀴 회전 여부

			moveWheel(n-1, dir); // 자기 자신 회전

			if(n == 1) // 오른쪽 바퀴 세개에 대해서 회전
			{
				if(w12 == true) // 두번째 바퀴 회전
				{
					moveWheel(1, -dir);

					if(w23 == true) // 세번째 바퀴 회전
					{
						moveWheel(2, dir);

						if(w34 == true) // 네번째 바퀴 회전
							moveWheel(3, -dir);
					}
				}
			}

			if(n == 2) // 두번째 바퀴일 경우
			{
				if(w12 == true)
					moveWheel(0, -dir); // 첫번째 바퀴 회전
				if(w23 == true)
				{
					moveWheel(2, -dir); // 세번째 바퀴 회전
					if(w34 == true)
						moveWheel(3,dir); // 네번째 바퀴 회전
				}
			}

			if(n == 3)
			{
				if(w23 == true)
				{
					moveWheel(1, -dir); // 두번째 바퀴 회전
					if(w12 == true)
						moveWheel(0, dir); // 첫번째 바퀴 회전
				}
				if(w34 == true)
					moveWheel(3, -dir); // 네번째 바퀴 회전
			}

			if(n == 4) // 마지막 바퀴일 경우, 왼쪽 바퀴들에 대해 회전
			{
				if(w34 == true)
				{
					moveWheel(2, -dir); // 세번째 바퀴 회전
					if(w23 == true)
					{
						moveWheel(1,dir); // 두번째 바퀴 회전
						if(w12 == true)
							moveWheel(0,-dir); // 첫번째 바퀴 회전
					}
				}
			}
		}

		int score = 0;
		for(int i=0; i<4; i++)
		{
			if(wheel[i][0] == 1) // S극일 경우, 점수 추가
				score += (int)pow(2.0,i);
		}
		printf("#%d %d\n", line++, score);
	}
}

