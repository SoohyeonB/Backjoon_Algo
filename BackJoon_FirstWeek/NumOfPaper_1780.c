#include <stdio.h>
#include <stdlib.h>
int N;
int paper[2188][2188];
int ans[3];
int check;

void solve(int x, int y, int size) {

	check = paper[x][y];

	for (int i = x; i < x + size; i++)
		for (int j = y; j < y + size; j++)
		{
			if (paper[i][j] != paper[x][y])
			{
				solve(x, y, size / 3);
				solve(x + size * 1 / 3, y, size / 3);
				solve(x + size * 2 / 3, y, size / 3);
				solve(x, y + size * 1 / 3, size / 3);
				solve(x + size * 1 / 3, y + size * 1 / 3, size / 3);
				solve(x + size * 2 / 3, y + size * 1 / 3, size / 3);
				solve(x, y + size * 2 / 3, size / 3);
				solve(x + size * 1 / 3, y + size * 2 / 3, size / 3);
				solve(x + size * 2 / 3, y + size * 2 / 3, size / 3);
				return;
			}
		}
	ans[paper[x][y] + 1]++;
	return;
}

int main()
{
	scanf_s("%d",&N);

	for (int i = 0; i < N; i++)
		for (int j = 0; j < N; j++)
			scanf_s("%d", &paper[i][j]);

	solve(0, 0, N);

	for (int i = 0; i < 3; i++) {
		printf("%d\n", ans[i]);
	}

}