#include <stdio.h>
#include <stdlib.h>

/*1991번 pre, in, post order결과 출력*/
/*linked list로 구현*/

typedef struct TreeNode {
	char data;
	TreeNode* left, right;
}TreeNode;

TreeNode* init(char key) {
	TreeNode* newNode = (TreeNode*)malloc(sizeof(TreeNode*));
	newNode->data = key;
	newNode->left = NULL;
	newNode->right = NULL;
	return newNode;
}

TreeNode* putNode(TreeNode*node, char data, char left, char right) {
	TreeNode* newNode = (TreeNode*)malloc(sizeof(TreeNode*));

	if (node->data == '.') return node;
	else {
		node->data = data;
		putNode(newNode, )
	}


}

void preorder(TreeNode* p) {
	if (p == NULL) return;
	printf("%c", p->data);
	preorder(p->left);
	preorder(p->right);
}

void inorder(TreeNode* p ) {
	if (p == NULL) return;
	preorder(p->left);
	printf("%c", p->data);
	preorder(p->right);
}

void postorder(TreeNode* p) {
	if (p == NULL) return;
	preorder(p->left);
	preorder(p->right);
	printf("%c", p->data);
}

int main() {
	int nodeNum;
	char left, data, right;
	scanf_s("%d", &nodeNum);
	TreeNode* list[] = (char*)malloc(sizeof(char) * nodeNum);

	TreeNode* root = init('A');	//루트 노드 생성

	//입력 parent left right
	for (int i = 0; i < nodeNum; i++) {
		TreeNode* p = (TreeNode*)malloc(sizeof(TreeNode*));
		scanf_s("%s %s %s", &left, &data, &right);
		putNode(p, data, left, right);
	}

	return 0;
}