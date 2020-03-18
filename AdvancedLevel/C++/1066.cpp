#include <iostream>
#include <algorithm>
using namespace std;

struct Node {
	int data, height;
	Node *lChild, *rChild;
};

int getHeight(Node* root) {
	if(root == NULL) //空结点高度为0
		return 0;
	return root->height;
}

void leftRotate(Node* &root) { //左旋
	Node* tmp = root->rChild; //tmp指向root的右子树
	root->rChild = tmp->lChild; //将右孩子的左子树 作为 root的右子树
	tmp->lChild = root; //将root 作为 右子树的左子树(使右子树成为新的root)
	root->height = max(getHeight(root->lChild), getHeight(root->rChild)) + 1; //更新左子树树高
	root = tmp; //更新root(右子树成为新的root)
	root->height = max(getHeight(root->lChild), getHeight(root->rChild)) + 1; //更新树高
}

void rightRotate(Node* &root) { //右旋
	Node* tmp = root->lChild; //tmp指向root的左子树
	root->lChild = tmp->rChild; //将左孩子的右子树 作为 root的左子树
	tmp->rChild = root; //将root 作为 左子树的右子树(使左子树成为新的root)
	root->height = max(getHeight(root->lChild), getHeight(root->rChild)) + 1; //更新右子树树高
	root = tmp; //更新root(右子树成为新的root)
	root->height = max(getHeight(root->lChild), getHeight(root->rChild)) + 1; //更新树高
}

void insert(Node* &root, int data) {
	if(root == NULL) { //到达空结点，新建结点
		root = new Node;
		root->data = data;
		root->height = 1; //结点初始高度为1
		root->lChild = root->rChild = NULL;
		return;
	}
	if(data < root->data) { //权值比当前根结点小
		insert(root->lChild, data); //往左子树插入
		root->height = max(getHeight(root->lChild), getHeight(root->rChild)) + 1; //更新树高
		if(getHeight(root->lChild) - getHeight(root->rChild) == 2) { //当前结点平衡因子为2
			if(data > root->lChild->data) //LR树型
				leftRotate(root->lChild); //左子树先左旋
			rightRotate(root); //右旋
		}
	} else { //权值比当前根结点大
		insert(root->rChild, data); //往右子树插入
		root->height = max(getHeight(root->lChild), getHeight(root->rChild)) + 1; //更新树高
		if(getHeight(root->lChild) - getHeight(root->rChild) == -2) { //当前结点平衡因子为-2
			if(data < root->rChild->data) //RL树型
				rightRotate(root->rChild); //右子树先左旋
			leftRotate(root); //左旋
		}
	}
}

int main() {
	int N, data;
	cin >> N;
	Node* root = NULL;
	for(int i = 0; i < N; i++) {
		cin >> data;
		insert(root, data);
	}
	cout << root->data;
	return 0;
}