#include <iostream>
#include <cstring>
#include <vector>
using namespace std;

int map[21][21];
int built[21][21];
int builtYN[21][2]; // 가로줄 세로줄 설치 가능 여부
int t,line = 1;
int n, x; // 변의 길이, 경사로 높이

int main()
{
	scanf("%d", &t);
	while(t--)
	{
		memset(map, 0, sizeof(map));
		memset(built, 0, sizeof(built));
		memset(builtYN, 0, sizeof(builtYN));
		scanf("%d %d", &n, &x);

		// 입력받기
		for(int i=0; i<n; i++)
			for(int j=0; j<n; j++)
				scanf("%d", &map[i][j]);

		// 가로 방향 검사
		for(int i=0; i<n; i++)
		{	
			int prev = map[i][0];
			for(int j=1; j<n; j++)
			{
				bool same = true;
				// 이전 좌표값과 다르고 지형이 낮을 경우 경사로 설치 필요
				if(prev != map[i][j] && prev > map[i][j])
				{
					for(int k=j; k<j+x; k++)
					{
						// 지형이 다르거나, 지형의 높이가 같지만 이미 설치했거나, 높이가 1 넘게 차이날 경우
						if(map[i][j] != map[i][k] || (map[i][j] == map[i][k] && built[i][k] != 0) || abs(prev - map[i][j]) > 1)
						{
							same = false;
							break;
						}
					}
					if(same == true)
					{
						for(int k=j; k<j+x; k++)
							built[i][k] = 1; // 경사로 설치
					}
					else
					{
						builtYN[i][0] = -1; // 이 라인에는 경사로 설치 불가
						break;
					}
				}
				// 이전 좌표값과 다르고 지형이 높은 경우, 이전 지형에 경사로 설치 필요
				else if(prev != map[i][j] && prev < map[i][j])
				{
					same = true;
					for(int k=j-1; k>=j-x; k--)
					{
						if(prev != map[i][k] || (prev == map[i][k] && built[i][k] != 0) || abs(prev - map[i][j]) > 1)
						{
							same = false;
							break;
						}
					}
					if(same == true)
					{
						for(int k=j-1; k<prev-x+1; k++)
							built[i][k] = 1; // 경사로 설치
					}
					else
					{
						builtYN[i][0] = -1; // 경사로 설치 불가
						break;
					}
				}
				prev = map[i][j];
			}
		}
		
		memset(built, 0, sizeof(built)); // 경사로 설치 초기화

		// 세로 방향 검사
		for(int i=0; i<n; i++)
		{	
			int prev = map[0][i];
			for(int j=1; j<n; j++)
			{
				bool same = true;
				// 이전 좌표값과 다르고 지형이 낮을 경우 경사로 설치 필요
				if(prev != map[j][i] && prev > map[j][i])
				{
					for(int k=j; k<j+x; k++)
					{
						// 지형이 다르거나, 지형의 높이가 같지만 이미 설치했거나, 높이가 1 넘게 차이날 경우
						if(map[j][i] != map[k][i] || (map[j][i] == map[k][i] && built[k][i] != 0) || abs(prev - map[j][i]) > 1)
						{
							same = false;
							break;
						}
					}
					if(same == true)
					{
						for(int k=j; k<j+x; k++)
							built[k][i] = 1; // 경사로 설치
					}
					else
					{
						builtYN[i][1] = -1;
						break;
					}
				}
				// 이전 좌표값과 다르고 지형이 높은 경우, 이전 지형에 경사로 설치 필요
				else if(prev != map[j][i] && prev < map[j][i])
				{
					same = true;
					for(int k=j-1; k>=j-x; k--)
					{
						if(prev != map[k][i] || (prev == map[k][i] && built[k][i] != 0) || abs(prev - map[j][i]) > 1)
						{
							same = false;
							break;
						}
					}
					if(same == true)
					{
						for(int k=j-1; k<prev-x+1; k++)
							built[k][i] = 1; // 경사로 설치
					}
					else
					{
						builtYN[i][1] = -1;
						break;
					}
				}
				prev = map[j][i];
			}
		}

		// 경사로를 설치할 수 없는 라인을 제외한 개수를 구함
		int result = 0;
		for(int i=0; i<n; i++)
			for(int j=0; j<2; j++)
				if(builtYN[i][j] != -1)
					result += 1;

		printf("#%d %d\n", line++, result);
	}
}