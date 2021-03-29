#include <stdio.h>
#include <stdlib.h>

typedef struct ListNode {
	int rank;				//순서
	int oderedNum;			//넣었을 때 당시의 인덱스 값
	struct ListNode* link;
}ListNode;

typedef struct {
	ListNode* head;
}LinkedListType;

void init(LinkedListType* L) {
	L->head = NULL;
}

void enqueue(LinkedListType* L, int item) {
	ListNode* node = (ListNode*)malloc(sizeof(ListNode));
	ListNode* before = L->head;
	while (before->link != NULL) {
		before = before->link;
		if (before->link == NULL) break;
	}
	//node->oderedNum = orderedN;
	node->rank = item;
	node->link = NULL;
	before->link = node;
}

int dequeue(LinkedListType* L) {
	ListNode* removed;

	if (L->head == NULL) return NULL;
	removed = L->head;
	L->head = removed->link;

	free(removed);
	return L->head->rank;
}

int get(LinkedListType* L, int pos) {
	ListNode* p = L->head;
	for (int i = 1; i < pos; i++)
		p = p->link;
	return p->rank;
}
void changeData(LinkedListType* L, int pos, int data) {
	ListNode* p = L->head;
	for (int i = 1; i < pos; i++)
		p = p->link;
	p->rank = data;
}
void swap(LinkedListType* L, int pos1, int pos2) {
	ListNode* p1 = L->head;
	ListNode* p2 = L->head;

	for (int i = 1; i < pos1; i++) {
		p1 = p1->link;
	}
	int tmp = p1->rank;
	for (int i = 1; i < pos2; i++) {
		p2 = p2->link;
	}
	p1->rank = p2->rank;
	p2->rank = tmp;
}

//선택 정렬
int selectArg(LinkedListType* Q, int n) {
	int min;

	for (int i = 0; i < n - 1; i++) {
		min = i;
		for (int j = i + 1; j < n; j++) {
			if (get(&Q, j) < get(&Q, min))
				min = j;
		}
		swap(&Q, i, min);
	}
}

//삽입정렬
void insertArg(LinkedListType* Q, int n) {
	int save;
	for (int i = 1; i < n; i++) {
		save = get(&Q, i);
		int j = i - 1;
		while ((j >= 0) && (get(&Q, j) > save)) {
			changeData(&Q, j + 1, get(&Q, j));
			j--;
		}
		changeData(&Q, j + 1, save);
	}
}

int printOrder(LinkedListType *Q, int n, int rank) {
	int cnt = 0;
	ListNode* p = Q->head;

	for (int i = 0; i < n; i++) {
		if (get(&Q, i) == rank) {
			break;
		}
		p = p->link;
		cnt++;
	}
	return cnt;

}

int main() {
	int testCase;	//테스트 케이스 수
	int n; //문서의 개수
	int m; //큐에서 몇번째에 놓여있는지 나타내는 정수
	LinkedListType Q;
	init(&Q);

	//scanf_s("%d", &testCase);
	//for (int i = 0; i < testCase; i++) {
		scanf_s("%d %d", &n, &m);

		//큐 채우기
		for (int j = 0; j < n; j++) {
			int priorityNum;
			scanf_s("%d ", &priorityNum);
			enqueue(&Q, priorityNum);

		}
		int key = get(&Q, m); //m번째 노드의 우선순위 값
		//정렬
		insertArg(&Q, n);
		selectArg(&Q, n);

		printf("%d\n", printOrder(&Q, n, key));

	//}

	return 0;
}

