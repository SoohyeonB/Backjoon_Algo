#include <iostream>
#include <queue>
#include <stdio.h>
using namespace std;


/* 우선큐 문제로 순서대로 정렬해주기
* 현재 문서의 중요도가 제일 높지 않다면 순서대로 정렬하는게 아니라 
* 큐의 맨끝에 배열한다.
*/
int priorityQ() {

}

int main(int argc, char* argv[]) {
	int testCase;	//테스트 케이스 수
	int n; //문서의 개수
	int m; //큐에서 몇번째에 놓여있는지 나타내는 정수
	queue<int> Q;  //문서가 들어갈 큐

	cin >> testCase;
	for (int i = 0; i < testCase; i++) {
		cin >> n;
		cin >> m;

	}
	

	m = priorityQ();
	printf("%d", m);
	return 0;
}