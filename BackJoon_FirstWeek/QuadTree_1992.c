#include <stdio.h>
#include <stdlib.h>

/*????Ʈ?? 1992*/

int board[64][64];

int check(int y, int x, int N) {
    int temp = board[y][x];
    for (int i = y; i < y + N; i++) {
        for (int j = x; j < x + N; j++) {
            if (temp != board[i][j]) {
                return 0;
            }
        }
    }
    return 1;
}

void solve(int y, int x, int N) {
    if (N == 0) return;

    else if (check(y, x, N)) {
        printf("%d", board[y][x]);
    }
    else {
        printf("(");
        int M = N / 2;
        for (int i = 0; i < 2; i++) {
            for (int j = 0; j < 2; j++) {
                solve(y + i * M, x + j * M, M);
            }
        }
        printf(")");
    }
}

int main(int argc, const char* argv[]) {

    int N;
    scanf_s("%d", &N);

    for (int i = 0; i < N; i++) {
        for (int j = 0; j < N; j++) {
            scanf_s("%1d", &board[i][j]);
        }
    }
    solve(0, 0, N);
    return 0;
}
