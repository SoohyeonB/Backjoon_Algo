#include <iostream>
#include <queue>
#include <stdio.h>
using namespace std;


/* 우선큐 문제로 순서대로 정렬해주기
* 현재 문서 우선순위대로 정렬 후 m번째 node의 출력 순서 출력해주기
*/

/*
3		//test case 개수 
1 0		//1번째 testcase  1개노드, [0] = m
5		//우선순위
4 2		//2번째 testcase  4개노드
1 2 3 4
6 0		//3번째
1 1 9 1 1 1*/

//선택정렬
int selectArg(queue<pair<int, int>> Q, int n) {
	int min;
	for (int i = 0; i < n - 1; i++) {
		min = i;
		for (int j = i + 1; j < n; j++) {
			if (Q.front().first < Q.front().second) {
				 Q.swap
			}
		}
	}
}

//삽입정렬
void insertArg(queue<pair<int, int>> Q, int n) {
	
}

//큐에서 순서 알려주기
int order(queue<pair<int, int>> Q, int m) {
	int answer;

}

int main(int argc, char* argv[]) {
	int testCase;	//테스트 케이스 수
	int n; //문서의 개수
	int m; //큐에서 몇번째에 놓여있는지 나타내는 정수
	queue<pair<int, int>> Q;  //문서가 들어갈 큐

	cin >> testCase;
	for (int i = 0; i < testCase; i++) {
		cin >> n;
		cin >> m;
		//큐 채우기
		for (int j = 0; j < n; j++) {
			int priorityNum;
			cin >> priorityNum;
			Q.push({ j, priorityNum });
		}
		//정렬
		insertArg(Q, n);
		selectArg(Q, n);

		cout <<order(Q, m) << endl;

	}
	

	return 0;
}