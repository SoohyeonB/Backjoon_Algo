#include <stdio.h>
#include <stdlib.h>
#include <time.h>

/*��͹��� - 6603 �ζ� */
//1. 1-49 �� k���� �̾� s�����
//2. s�߿��� 6���� �̾� ������ ������ ���� ���ϱ�
// DFSȰ��

int arr[14];
int answer[14];
int k;

//isVisited�� �湮�� Ȯ�ε����� �ʾҴµ� ��� ����..?
void DFS(int start, int depth) {
	int i;
	if (depth == 6) {	
		for (i = 0; i < 6; i++)
			printf("%d ", answer[i]);
		printf("\n");
	}
	else {
		for (i = start; i < k; i++) {
			answer[depth] = arr[i];
			DFS(i + 1, depth + 1);
		}
	}
}


void main() {
	int i;
	while (1) {
		scanf_s("%d", &k);
		if (k == 0) break;
		for (i = 0; i < k; i++)
			scanf_s("%d", &arr[i]);  //k���� ���� �Է�
		DFS(0, 0);
		printf("\n");
	}
}