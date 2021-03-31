#include <stdio.h> 
#include <string.h> 
int queue[2000001]; 
int front=0; int rear=-1; 
void clean(char arr[]); // �ʱ�ȭ�� �Լ� 
void push(int x); 
void pop(void); 
void size(void); 
void empty(void); 
int main(void) {
	int n, i, x;
	char command[6];
	scanf_s("%d", &n);
	for (i = 0; i < n; i++) {
		scanf_s("%s", command); // ��� �Է� 
		if (!strcmp(command, "push")) {
			scanf_s("%d", &x); push(x);
		}
		else if (!strcmp(command, "pop"))
			pop();
		else if (!strcmp(command, "size"))
			size();
		else if (!strcmp(command, "empty"))
			empty();
		else if (!strcmp(command, "front")) {
			if (rear - front + 1 == 0)
				printf("%d\n", -1);
			else printf("%d\n", queue[front]);
		}
		else if (!strcmp(command, "back")) {
			if (rear - front + 1 == 0)
				printf("%d\n", -1);
			else printf("%d\n", queue[rear]);
		}
		clean(command); // �ʱ�ȭ } 
		return 0;
	}
}
	void clean(char arr[]){ 
		int i;
		for(i=0;i<6;i++) 
			arr[i]='\0'; 
	}
	void push(int x){
		queue[++rear]=x;
	} 
	void pop(void){
		if(rear-front+1==0)
			printf("%d\n", -1); 
		else printf("%d\n", queue[front++]);
	} 
	void size(void){
		printf("%d\n", rear-front+1); 
	} 
	void empty(void){
		if(rear-front+1!=0) 
			printf("%d\n", 0);
		else printf("%d\n", 1); 
	}

