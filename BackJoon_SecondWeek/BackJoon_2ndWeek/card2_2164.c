#include <stdio.h>
#include<stdlib.h>

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

//����Ʈ �����
headNode* makeQueue(headNode* List, int data ) {
	ListNode* p = (ListNode*)malloc(sizeof(ListNode*));
	ListNode* before = (ListNode*)malloc(sizeof(ListNode*));
	before = List->head;
	p->data = data;
	while (before->link) {
		before = before->link;
	}
	before->link = p;
	return List;
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
headNode* enqueue(headNode* L, ListNode * node,int data) {
	ListNode* p = (ListNode*)malloc(sizeof(ListNode*));
	p->data = data;
	p->link = NULL;
	while (node) {
		node->link = p;
	}
	return L;

}

int doGame(headNode *L, int n) {
	ListNode* p = (ListNode*)malloc(sizeof(ListNode*));
	p = L->head;
	int num = 1;
	while (1) { //p�� ���� ��尡 NULL�� �ƴ� ���
		if (!(p->link)) { //p�� ������ ���϶� 
			return p->data;
			break;
		}
		else {
			//�������� ������
			if(num%2 !=0)
				dequeue(&L);
			//�������� �ڷ� ��������
			else {
				dequeue(&L);
				enqueue(&L, num);
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

	for (int i = 0; i < n; i++) { 
		list = makeQueue(&list, i + 1);
		//linked ����� 1-n���� 
	}
	printf("%d", doGame(&list, n));

	return 0;
}