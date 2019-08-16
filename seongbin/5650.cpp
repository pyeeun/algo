#include <iostream>
#include <string.h>
#include <algorithm>
using namespace std;

int matrix[100][100];
//int ball[100][100][4];
int check[100][100][4];
int wormhole[5][2];
int dx[4] = { 0, 0, -1, 1 };
int dy[4] = { -1, 1, 0, 0 };

int times;
int answer;

int main()
{
	int t, temp;
	scanf("%d", &t);
	temp = t;
	int n;
	int i, j, d;
	int k;
	int now_direction;
	int nx, ny;
	while (t--)
	{
		answer = 0;
		scanf("%d", &n);
		memset(wormhole, -1, sizeof(wormhole));
		for (i = 0; i < n; i++)
		{
			for (j = 0; j < n; j++)
			{
				scanf("%d", &(matrix[i][j]));
				if (matrix[i][j] >= 6 && matrix[i][j] <= 10)
				{
					if (wormhole[matrix[i][j] - 6][0] == -1)
						wormhole[matrix[i][j] - 6][0] = i * 1000 + j;
					else
						wormhole[matrix[i][j] - 6][1] = i * 1000 + j;

				}
			}
		}
		memset(check, -1, sizeof(check));
		//memset(ball, -1, sizeof(ball));
		for (i = 0; i < n; i++)
		{
			for (j = 0; j < n; j++)
			{
				if (matrix[i][j] != 0)
					continue;
				for (d = 0; d < 4; d++)
				{
					times = 0;
					now_direction = d;
					//x = j;
					//y = i;
					nx = j;
					ny = i;
					do
					{
						while (1)
						{
							nx += dx[now_direction];
							ny += dy[now_direction];
							if (ny < 0 || nx < 0 || ny >= n || nx >= n)
								break;
							//else if (ball[ny][nx][now_direction] != -1)
							//	break;
							else if (matrix[ny][nx] != 0)
								break;
							else if (nx == j && ny == i)
								break;
						}

						if (ny < 0 || nx < 0 || ny >= n || nx >= n)
						{
							times++;
							if (now_direction == 0)
								now_direction = 1;
							else if (now_direction == 1)
								now_direction = 0;
							else if (now_direction == 2)
								now_direction = 3;
							else
								now_direction = 2;
						}
						/*else if (ball[ny][nx][now_direction] != -1) // 여기 부분은 조금 고민이 필요.
						{
							ball[i][j][now_direction] = ball[ny][nx][now_direction];
							break;
						}*/
						else if (matrix[ny][nx] == -1)
							break;
						else if (matrix[ny][nx] != 0)
						{
							times++;
							if (matrix[ny][nx] == 1)
							{
								if (now_direction == 0)
									now_direction = 1;
								else if (now_direction == 1)
									now_direction = 3;
								else if (now_direction == 2)
									now_direction = 0;
								else
									now_direction = 2;
							}
							else if (matrix[ny][nx] == 2)
							{
								if (now_direction == 0)
									now_direction = 3;
								else if (now_direction == 1)
									now_direction = 0;
								else if (now_direction == 2)
									now_direction = 1;
								else
									now_direction = 2;
							}
							else if (matrix[ny][nx] == 3)
							{
								if (now_direction == 0)
									now_direction = 2;
								else if (now_direction == 1)
									now_direction = 0;
								else if (now_direction == 2)
									now_direction = 3;
								else
									now_direction = 1;
							}
							else if (matrix[ny][nx] == 4)
							{
								if (now_direction == 0)
									now_direction = 1;
								else if (now_direction == 1)
									now_direction = 2;
								else if (now_direction == 2)
									now_direction = 3;
								else
									now_direction = 0;
							}
							else if (matrix[ny][nx] == 5)
							{
								if (now_direction == 0)
									now_direction = 1;
								else if (now_direction == 1)
									now_direction = 0;
								else if (now_direction == 2)
									now_direction = 3;
								else
									now_direction = 2;
							}
							else if (matrix[ny][nx] >= 6 && matrix[ny][nx] <= 10)
							{
								k = matrix[ny][nx];
								times--;
								if (wormhole[k - 6][0] / 1000 == ny && wormhole[k - 6][0] % 1000 == nx)
								{
									ny = wormhole[k - 6][1] / 1000;
									nx = wormhole[k - 6][1] % 1000;
								}
								else
								{
									ny = wormhole[k - 6][0] / 1000;
									nx = wormhole[k - 6][0] % 1000;
								}
							}
						}
		
						if (nx == j && ny == i)
							break;
					} while (1);
					//ball[i][j][d] = times;
					answer = max(answer, times);
				}
			}
		}
		printf("#%d %d\n", temp - t, answer);
	}

	return 0;
}