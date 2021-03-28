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



//맨앞 노드 삭제
headNode* dequeue(headNode* L) {
	ListNode* p = (ListNode*)malloc(sizeof(ListNode*));
	p = L->head;
	L->head = p->link->link;
	free(p);
	return L;
}

//맨뒤에 add
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

//리스트 만들기
void makeQueue(headNode* List, int n) {

	for (int i = 0; i < n; i++) {
		List = enqueue(&List, i);		//1~n 까지 카드 쌓음
	}
	
}

int doGame(headNode *L, int n) {
	ListNode* p = (ListNode*)malloc(sizeof(ListNode*));
	p = L->head;
	int num = 1;
	while (1) { //p의 다음 노드가 NULL이 아닐 경우
		if (p->link ==NULL) { //p가 마지막 장일때 
			return p->data;
			break;
		}
		else {
			//맨위에꺼 버리기
			if(num%2 !=0)
				L = dequeue(&L);
			//맨위에꺼 뒤로 가져오기
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
	scanf_s("%d", &n);	//카드 개수 입력받기

	//linked 만들기 1~n 까지 
	makeQueue(&list, n);



	printf("%d", doGame(&list, n));

	return 0;
}