/*
* 덱 구현하기 deque
* 구조체 이용한 방법
*/
#include <stdlib.h>
#include <stdio.h>

typedef struct Node {
	int data;
	struct Node* link;
}Node;

typedef struct Deque {
	Node* head;
}Deque;

void init(Deque* D) {
	D->head = NULL;
}

void push_front(Deque* D, int new) {
	Node* p = (Node*)malloc(sizeof(Node));
	p->data = new;
	p->link = D->head->link;
	D->head = p;
}
void push_back(Deque* D, int new) {
	Node* p = (Node*)malloc(sizeof(Node));
	p->data = new;
	p = D->head;
	while (p->link) {
		p = p->link;
	}
}
void pop_front(Deque* D) {
	if (D->head == NULL)
		printf("-1\n");
	else {
		Node* p = (Node*)malloc(sizeof(Node));
		p = D->head->link;
		D->head->link = p->link;
		printf("%d\n", p->data);
		free(p);
	}
}
void pop_back(Deque* D) {
	if (D->head == NULL)
		printf("-1\n");
	else {
		Node* p = (Node*)malloc(sizeof(Node));
		Node* before = (Node*)malloc(sizeof(Node));

		p = D->head;
		while (p->link) {
			before = p;
			p = p->link;
		}
		before->link = NULL;
		printf("%d\n", p->data);
		free(p);
	}
}
void size(Deque *D) {
	Node* p = (Node*)malloc(sizeof(Node));
	p = D->head;
	int dequeSize = 0;

	while (p->link) {
		p = p->link;
		dequeSize++;
	}
	printf("%d\n", dequeSize);
}
void empty(Deque *D) {
	if (D->head == NULL)
		printf("1\n");
	else
		printf("0\n");
}
void front(Deque* D) {
	if (D->head == NULL)
		printf("-1\n");
	else {
		printf("%d\n",D->head->link->data);
	}
}
void back(Deque* D) {
	if (D->head == NULL)
		printf("-1\n");
	else {
		Node* p = (Node*)malloc(sizeof(Node));
		p = D->head;
		while (p->link) {
			p = p->link;
		}
		printf("%d\n", p->data);
	}
}


int main() {
	Node* Deque = (Node*)malloc(sizeof(Node));
	init(Deque);

	int n;
	scanf_s("%d", &n); //명령의 수
	char order[10] = {' ',};

	for (int i = 0; i < n; i++) {
		for (int j = 0; j < 10; j++) {
			scanf_s("%c", &order); //명령의 수
		}
		if (order[0] == 'f') 	//front
			front(&Deque);
		else if (order[0] == 'b') //back
			back(&Deque);
		else if (order[0] == 's') //size
			size(&Deque);
		else if (order[0] == 'e') //empty
			empty(&Deque);
		else if(order[1] == 'u') { //push
			int what;
			scanf_s("%d", &what);
			if (order[5] == 'b')  //pushBack
				push_back(&Deque, what);
			else if (order[5] == 'f')		//pushFront
				push_front(&Deque, what);
		}
		else if (order[1] == 'o') { //pop
			if (order[4] == 'b')  //popBack
				pop_back(&Deque);
			else if (order[4] == 'f')		//popFront
				pop_front(&Deque);
		}
		
	}

	return 0;
}