#include <iostream>
#include <queue>
#include <stdio.h>
using namespace std;


/* �켱ť ������ ������� �������ֱ�
* ���� ���� �켱������� ���� �� m��° node�� ��� ���� ������ֱ�
*/

/*
3		//test case ���� 
1 0		//1��° testcase  1�����, [0] = m
5		//�켱����
4 2		//2��° testcase  4�����
1 2 3 4
6 0		//3��°
1 1 9 1 1 1*/

//��������
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

//��������
void insertArg(queue<pair<int, int>> Q, int n) {
	
}

//ť���� ���� �˷��ֱ�
int order(queue<pair<int, int>> Q, int m) {
	int answer;

}

int main(int argc, char* argv[]) {
	int testCase;	//�׽�Ʈ ���̽� ��
	int n; //������ ����
	int m; //ť���� ���°�� �����ִ��� ��Ÿ���� ����
	queue<pair<int, int>> Q;  //������ �� ť

	cin >> testCase;
	for (int i = 0; i < testCase; i++) {
		cin >> n;
		cin >> m;
		//ť ä���
		for (int j = 0; j < n; j++) {
			int priorityNum;
			cin >> priorityNum;
			Q.push({ j, priorityNum });
		}
		//����
		insertArg(Q, n);
		selectArg(Q, n);

		cout <<order(Q, m) << endl;

	}
	

	return 0;
}