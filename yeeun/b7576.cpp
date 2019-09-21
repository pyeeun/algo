#define _CRT_SECURE_NO_WARNINGS
#include <iostream>
#include <queue>
using namespace std;

// �丶�� ����ü
struct tomato
{
	int x, y, day; // ��ǥ, ��
};

// �������
int dx[] = { -1, 0, 1, 0 };
int dy[] = { 0, 1, 0, -1 };

queue<tomato> q;
int n, m;
int box[1001][1001];
int res = 0;

int getTomato()
{
	int state = 1; // �丶�� ����

	// �ڽ� ���� ��� �丶�� Ž��
	for (int i = 0; i < m; i++)
	{
		for (int j = 0; j < n; j++)
		{
			if (box[i][j] == 0) // �ϳ��� �� �;��� ���, ����
				return -1;
			else
				res = max(res, box[i][j]); // ��� �丶�䰡 ���� �� �ִ� �ּ� �Ⱓ(�ִ밪) ����
		}
	}
	return state;
}

void bfs()
{
	while (!q.empty())
	{
		// ���� �丶���� ����
		int cx = q.front().x;
		int cy = q.front().y;
		int cm = q.front().day;
		q.pop();

		// �����¿�� Ž��
		for (int i = 0; i < 4; i++)
		{
			int nx = cx + dx[i];
			int ny = cy + dy[i];
			int nd = cm + 1;

			// ������ �Ѿ�� �ʰ�, ���� �丶�䰡 ���� ���� �丶���̰�,
			// ���� �丶��� ���� �丶���� ��츸 ť�� ����
			if (!(nx < 0 || ny < 0 || nx >= m || ny >= n) 
				&& box[nx][ny] == 0 && box[cx][cy] >= 1)
			{
				q.push({ nx, ny, nd });
				box[nx][ny] = nd;
			}
		}
	}
}

int main()
{
	int emptybox = 0;
	scanf("%d %d", &n, &m);

	for (int i = 0; i < m; i++)
	{
		for (int j = 0; j < n; j++)
		{
			scanf("%d", &box[i][j]);

			if (box[i][j] == 1) // ���� �丶���� ���
				q.push({ i, j, 0 });
			else if (box[i][j] == -1) // �� �ڽ��� ���
				emptybox++;
		}
	}

	// �ڽ� �ȿ� �ִ� �丶�䰡 ��� ���� �丶���� ���
	if ((q.size() + emptybox) == (n * m))
		printf("0");
	else
	{
		bfs();

		if (getTomato() == -1) // �丶�䰡 ��� ���� �ʾ��� ���
			printf("-1");
		else // �丶�䰡 ��� �;��� ���
			printf("%d", res);
	}
}