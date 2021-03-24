#include <stdio.h>
#include <stdlib.h>
/*2448번 별찍기 11번*/
//세 단계로 나눠서 재귀함수 구현
char arr[3073][6145];

void func(int n, int r, int c) {
	if (n == 3) {
		//삼각형 모양으로 찍기
		arr[r][c] = '*';
		arr[r + 1][c - 1] = '*';
		arr[r + 1][c + 1] = '*';
		for (int i = c - 2; i <= c + 2; i++)
			arr[r + 2][i] = '*';
		return;
	}
	func(n / 2, r, c);
	func(n / 2, r + n / 2, c - n / 2);
	func(n / 2, r + n / 2, c + n / 2);

}

void main() {
	int N;
	scanf_s("%d", &N);

	func(N, 1, N);

	for (int i = 1; i <= N; i++) {
		for (int j = 1; j <= 2 * N - 1; j++) {
			if (arr[i][j] != '*')
				arr[i][j] = ' ';
		}
	}

	for (int i = 1; i <= N; i++) {
		for (int j = 1; j <= 2 * N - 1; j++) {
			printf("%c", arr[i][j]);
		}
		printf("\n");
	}

}