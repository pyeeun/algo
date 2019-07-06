#define _CRT_SECURE_NO_WARNINGS
#include <iostream>
#include <string>
#include <cstring>
using namespace std;

int map[8][8];
int map_rotate[8][8];
int t; // �׽�Ʈ���̽� ����
int n; // �� ���� ����
int line = 1;

void rotate()
{
	string result[8][3];

	// 90�� 180�� 270�� ȸ��
	for (int cnt = 0; cnt < 3; cnt++)
	{
		for (int i = 0; i < n; i++)
		{
			for (int j = 0; j < n; j++)
			{
				map_rotate[j][n - (i + 1)] = map[i][j];
			}
		}

		memcpy(map, map_rotate, sizeof(map_rotate)); // �迭 ����

		for (int i = 0; i < n; i++)
		{
			for (int j = 0; j < n; j++)
			{
				// ���ڿ� ��ȯ �� ����
				result[i][cnt] = result[i][cnt] + to_string(map[i][j]);
			}
		}
	}
	printf("#%d\n", line++);

	// ���
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

		// ����ڷκ��� �迭 �Է� ����
		for (int i = 0; i < n; i++)
			for (int j = 0; j < n; j++)
				scanf("%d", &map[i][j]);

		rotate();
	}
}