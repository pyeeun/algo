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

		int view = 0; // 조망권이 확보된 아파트의 수

		for(int i=2; i<width+2; i++) // 양쪽 두칸을 비워둔채로 배열에 삽입 
			scanf("%d", &apt[i]);

		for(int w=2; w<width+2; w++)
		{
			int cur_width = apt[w]; // 현재 아파트의 높이
			int left = w-2; // 왼쪽방향으로 체크할 범위
			int right = w+2; // 오른쪽방향으로 체크할 범위

			// 왼쪽 방향으로 조망 탐색
			int leftview = 1, leftheight = -1;
			for(int i=w-1; i>=left; i--)
			{
				if(apt[w] < apt[i]) // 현재 아파트보다 더 높을 경우 중단
				{
					leftview = 0;
					break;
				}
				else
				{
					// 현재 층에서 2칸 왼쪽에 있는 층을 빼서 조망권 세대 수 구함
					if(leftheight == -1) // 첫번째 비교일 경우, 첫번째 값을 넣어줌
						leftheight = apt[w] - apt[i];
					else // 두번째 비교일 경우, 더 차이가 적게 나는 값(높은 층을 우선)
						leftheight = min(leftheight, apt[w] - apt[i]);
				}
			}

			// 오른쪽 방향으로 조망 탐색
			int rightview = 1, rightheight = -1;
			for(int i=w+1; i<=right; i++)
			{
				if(apt[w] <= apt[i]) // 현재 아파트보다 더 높을 경우 중단
				{
					rightview = 0;
					break;
				}
				else
				{
					// 현재 층에서 2칸 왼쪽에 있는 층을 빼서 조망권 세대 수 구함
					if(rightheight == -1) // 첫번째 비교일 경우, 첫번째 값을 넣어줌
						rightheight = apt[w] - apt[i];
					else // 두번째 비교일 경우, 더 차이가 적게 나는 값(높은 층을 우선)
						rightheight = min(rightheight, apt[w] - apt[i]);
				}
			}

			// 좌우 모두 조망권을 확보했을 경우, 조망권 세대 1 증가
			if(leftview == 1 && rightview == 1)
			{
				view = view + min(leftheight, rightheight);
			}
		}
		printf("#%d %d\n", line++, view);
	}
}