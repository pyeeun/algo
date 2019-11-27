#include <iostream>
#define _CRT_SECURE_NO_WARNINGS
using namespace std;

int n;
int mag[10];
int mass[10];
double val[10];
int now_index;
double now_value;
int point;
int alright;
int denominator;//ºÐ¸ð

double calculate_point(int k)
{
	int i;
	double d = 1;
	for (i = 0; i < k; i++)
		d *= 10;

	return d;
}

void solve(int p)
{
	int i, j;
	double k;
	k = calculate_point(p);
	double x = now_value;
	double left = 0;
	double right = 0;
	int state;
	int tempi = 10;
	if (p == 1)
		tempi = (mag[now_index + 1] - mag[now_index]) * 10;
	for (i = 1; i <= tempi; i++)
	{
		//x += k;
		left = 0;
		right = 0;
		for (j = 0; j < n; j++)
		{
			val[j] = mass[j] / ((mag[j] - (x + i * (1 / k)))*(mag[j] - (x + i * (1 / k))));
			if (now_index >= j)
				left += val[j];
			else
				right += val[j];
		}

		if (i == 1)
		{
			if (left < right)
				state = 0;
			else if (left > right)
				state = 1;
			else
				state = 2;
		}
		else
		{
			if (left == right)
				state = 2;
			else if (left < right)
			{
				if (state == 1)
				{
					now_value = x + (i - 1) * (1 / k);
					return;
				}

			}
			else if (left > right)
			{
				if (state == 0)
				{
					now_value = x + (i - 1) * (1 / k);
					return;
				}
			}
		}

		if (state == 2)
		{
			now_value = x + i * (1 / k);
			alright = 1;
			return;
		}
	}
}

int main()
{
	int t, temp;
	scanf("%d", &t);
	temp = t;
	int i;

	while (t--)
	{
		scanf("%d", &n);
		for (i = 0; i < n; i++)
			scanf("%d", &(mag[i]));
		for (i = 0; i < n; i++)
			scanf("%d", &(mass[i]));
		alright = 0;

		printf("#%d ", temp - t);
		for (now_index = 0; now_index < n - 1; now_index++)
		{
			now_value = mag[now_index];
			for (point = 1; point <= 13; point++)
			{
				solve(point);
				if (alright == 1)
					break;
			}
			printf("%.10lf ", now_value);
		}
		printf("\n");
	}
	return 0;
}