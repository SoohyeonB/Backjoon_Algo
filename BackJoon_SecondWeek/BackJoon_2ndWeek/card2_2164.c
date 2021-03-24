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

//리스트 만들기
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

//맨앞 노드 삭제
headNode* dequeue(headNode* L) {
	ListNode* p = (ListNode*)malloc(sizeof(ListNode*));
	p = L->head;
	L->head = p->link->link;
	free(p);
	return L;
}

//맨뒤에 add
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
	while (1) { //p의 다음 노드가 NULL이 아닐 경우
		if (!(p->link)) { //p가 마지막 장일때 
			return p->data;
			break;
		}
		else {
			//맨위에꺼 버리기
			if(num%2 !=0)
				dequeue(&L);
			//맨위에꺼 뒤로 가져오기
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
	scanf_s("%d", &n);	//카드 개수 입력받기

	for (int i = 0; i < n; i++) { 
		list = makeQueue(&list, i + 1);
		//linked 만들기 1-n까지 
	}
	printf("%d", doGame(&list, n));

	return 0;
}