#define _CRT_SECURE_NO_WARNINGS
#include <iostream>
#include <string>
#include <cstring>
using namespace std;

int map[8][8];
int map_rotate[8][8];
int t; // 테스트케이스 개수
int n; // 한 변의 길이
int line = 1;

void rotate()
{
	string result[8][3];

	// 90도 180도 270도 회전
	for (int cnt = 0; cnt < 3; cnt++)
	{
		for (int i = 0; i < n; i++)
		{
			for (int j = 0; j < n; j++)
			{
				map_rotate[j][n - (i + 1)] = map[i][j];
			}
		}

		memcpy(map, map_rotate, sizeof(map_rotate)); // 배열 복사

		for (int i = 0; i < n; i++)
		{
			for (int j = 0; j < n; j++)
			{
				// 문자열 변환 후 붙임
				result[i][cnt] = result[i][cnt] + to_string(map[i][j]);
			}
		}
	}
	printf("#%d\n", line++);

	// 출력
	for (int i = 0; i < n; i++)
	{
		for (int j = 0; j < 3; j++)
		{
			cout << result[i][j] <<" ";
		}
		printf("\n");
	}
}

int main()
{
	scanf("%d", &t);

	while (t--)
	{
		scanf("%d", &n);

		// 사용자로부터 배열 입력 받음
		for (int i = 0; i < n; i++)
			for (int j = 0; j < n; j++)
				scanf("%d", &map[i][j]);

		rotate();
	}
}