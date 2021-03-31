#include <stdlib.h>
#include <stdio.h>

typedef struct Node {
	int data;
	struct Node* link;
}Node;

typedef struct queue {
	Node* head;
}queue;

void init(queue* D) {
	D->head = NULL;
}

void push(queue* D, int newData) {

	Node* p = (Node*)malloc(sizeof(Node));
	p = D->head;
	p->data = newData;

	while (p->link) {
		p = p->link;
	}
}
void pop(queue *D) {
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
void size(queue* D) {
	Node* p = (Node*)malloc(sizeof(Node));
	p = D->head;
	int dequeSize = 0;

	while (p->link) {
		p = p->link;
		dequeSize++;
	}
	printf("%d\n", dequeSize);
}
void empty(queue* D) {
	if (D->head == NULL)
		printf("1\n");
	else
		printf("0\n");
}
void front(queue* D) {
	if (D->head == NULL)
		printf("-1\n");
	else {
		printf("%d\n", D->head->link->data);
	}
}
void back(queue* D) {
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
	queue Q;
	init(&Q);

	int n;
	scanf_s("%d", &n); //명령의 수
	//getchar();
	for (int i = 0; i < n; i++) {
		//문자열 입력 받는 부분 이상함 ㅠ
		char order[10];
		gets(order);
		//printf("%s", order);

		if (order[0] == 'f') 	//front
			front(&Q);
		else if (order[0] == 'b') //back
			back(&Q);
		else if (order[0] == 's') //size
			size(&Q);
		else if (order[0] == 'e') //empty
			empty(&Q);
		else if (order[0] == 'p') { //push
			int what;
			scanf_s("%d", &what);
			if (order[1] == 'u')  //push
				push(&Q, what);
			else if (order[1] == 'o') { //pop
				pop(&Q, what);
			}
		}
	}
	return 0;
}