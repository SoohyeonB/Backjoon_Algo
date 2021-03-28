#include <iostream>
#include <cstring>
#include <queue>
#include <string>
#include <algorithm>

using namespace std;

//argc: os�� ���α׷��� ���������� ���޵Ǵ� �μ��� ����
//argv: ���α׷����� ���޵� ���� �μ� ��, cmdâ���� �ԷµǴ� ��� ���� ���ڿ��� ������
//		���� �����ͷ� ���ڿ� �迭�� ����Ŵ
int main(int argc, char* argv[]){
	int n;
	queue<int> q;

	cin >> n;

	//1~n ������ ī�带 ť�� push
	for (int i = 0; i < n; i++) {
		q.push(i + 1);
	}


	//pop push �ѹ��� ����� �ϴ°� �ƴ�...? 
	while (q.size() > 1) { //ť�� ������� ������
		q.pop();		//�� �տ� �ִ� ���� ����
		q.push(q.front()); //�� �������� ������ �� �ؿ� ����
		q.pop();		
	}

	cout << q.front() << endl;

	return 0;
}