#include <stdio.h>
#include <stdlib.h>
#include <time.h>

/*재귀문제 - 6603 로또 */
//1. 1-49 중 k개를 뽑아 s만들기
//2. s중에서 6개씩 뽑아 가능한 집합의 개수 구하기
// DFS활용

int arr[14];
int answer[14];
int k;

//isVisited로 방문이 확인되지도 않았는데 어떻게 가능..?
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
			scanf_s("%d", &arr[i]);  //k개의 숫자 입력
		DFS(0, 0);
		printf("\n");
	}
}