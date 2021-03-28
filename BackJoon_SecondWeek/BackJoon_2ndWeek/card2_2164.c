#include <stdio.h>
#include <stdlib.h>
#include <queue>
#include <algorithm>

typedef struct ListNode {
	int data;
	struct ListNode* link;
}ListNode;

typedef struct headNode {
	ListNode* head;
}headNode;

void init(headNode* L) {
	L->head = NULL;
}



//�Ǿ� ��� ����
headNode* dequeue(headNode* L) {
	ListNode* p = (ListNode*)malloc(sizeof(ListNode*));
	p = L->head;
	L->head = p->link->link;
	free(p);
	return L;
}

//�ǵڿ� add
headNode* enqueue(headNode* L, int data) {
	ListNode* before = (ListNode*)malloc(sizeof(ListNode*));
	ListNode* p = (ListNode*)malloc(sizeof(ListNode*));

	p->data = data;
	p->link = NULL;
	before = L->head;

	while (before->link) {
		before = before->link;
	}
	before->link = p;
	
	return L;

}

//����Ʈ �����
void makeQueue(headNode* List, int n) {

	for (int i = 0; i < n; i++) {
		List = enqueue(&List, i);		//1~n ���� ī�� ����
	}
	
}

int doGame(headNode *L, int n) {
	ListNode* p = (ListNode*)malloc(sizeof(ListNode*));
	p = L->head;
	int num = 1;
	while (1) { //p�� ���� ��尡 NULL�� �ƴ� ���
		if (p->link ==NULL) { //p�� ������ ���϶� 
			return p->data;
			break;
		}
		else {
			//�������� ������
			if(num%2 !=0)
				L = dequeue(&L);
			//�������� �ڷ� ��������
			else {
				L = dequeue(&L);
				L = enqueue(&L, num);
			}
			num++;
		}
	}
	
}

int main() {
	headNode* list;
	init(&list);


	int n;
	scanf_s("%d", &n);	//ī�� ���� �Է¹ޱ�

	//linked ����� 1~n ���� 
	makeQueue(&list, n);



	printf("%d", doGame(&list, n));

	return 0;
}