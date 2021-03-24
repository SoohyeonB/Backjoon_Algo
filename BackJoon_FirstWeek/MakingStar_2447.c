#include <stdio.h>
#include <stdlib.h>
#define size 6000
char arr[size][size] = { NULL };

/*별찍기 -10 (2447번)*/
// 쓰레기 같은 효율성^^...
int makeStar(int n, int m) {
	if (m == n * 3) return 0;
	else {
		if (m == 3) {
			for (int i = 0; i < n; i++) {
				for (int j = 0; j < n; j++) {
					if (i % 3 == 1 && j % 3 == 1)
						arr[i][j] = ' ';
					else
						continue;
				}
			}
		}
		else {
			for (int i = 0; i < n; i++) {
				for (int j = 0; j < n; j++) {
					if (m / 3 <= i && i < 2 * m / 3 && m / 3 <= j && j < 2 * m / 3) {
						arr[i][j] = ' ';
					}
					else
						arr[i][j] = arr[i % m][j % m];
				}
			}
		}
		makeStar(n, m * 3);
	}
}

int main() {
	int n = 0;
	scanf_s("%d", &n);
	for (int i = 0; i < n; i++) {
		for (int j = 0; j < n; j++)
			arr[i][j] = '*';
	}
	makeStar(n, 3);
	for (int i = 0; i < n; i++) {
		for (int j = 0; j < n; j++) {
			printf("%c", arr[i][j]);
		}
		printf("\n");
	}
	return 0;
}