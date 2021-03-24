#include <stdio.h>
#include <stdlib.h>
#include <math.h>

int n, r, c;
int result;

void recursion(int x, int y, int len) {
    if (y == r && x == c) {         //ã�� ��ǥ�� ����� ���
        printf("%d\n", result);
        return;
    }
    if (len == 1) {               // +1
        result++; return;
    }
    if (!(y <= r && r < y + len && x <= c && c < x + len)) { //
        result += len * len;
        return;
    }
    recursion(x, y, len / 2);                  //2��и�
    recursion(x + len / 2, y, len / 2);            //1��и�
    recursion(x, y + len / 2, len / 2);            //3��и�
    recursion(x + len / 2, y + len / 2, len / 2);   //4��и�
}

int main() {
    scanf_s("%d", &n);
    scanf_s("%d", &r);
    scanf_s("%d", &c);
    recursion(0, 0, pow(2, n));

    return 0;
}