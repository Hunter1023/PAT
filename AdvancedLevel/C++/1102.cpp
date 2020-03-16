#include <iostream>
#include <queue>
using namespace std;

struct Node {
	int lChild, rChild;
} node[10]; //静态链表存储二叉树

int notRoot[10] = {0}; //只有根结点没有父结点

int transToNum(char c) {
	int num;
	if(c == '-') {
		num = -1;
	} else {
		num = c - '0';
		notRoot[num] = 1; //作为子结点，不可能是根节点
	}
	return num;
}

void invertTree(int root) { //通过后序遍历交换左右子树，完成二叉树的反转
	if(root == -1) //递归边界：空树
		return;
	invertTree(node[root].lChild);
	invertTree(node[root].rChild);
	int tmp = node[root].lChild;
	node[root].lChild = node[root].rChild;
	node[root].rChild = tmp;
}
	
void levelOrder(int root) {
	queue<int> q;
	q.push(root);
	int cnt = 0;
	while(!q.empty()) {
		int now = q.front();
		q.pop();
		if(cnt > 0)
			cout << ' ';
		cnt++;
		cout << now;
		if(node[now].lChild != -1)
			q.push(node[now].lChild);
		if(node[now].rChild != -1)
			q.push(node[now].rChild);
	}
	cout << endl;
}

void inOrder(int root, int &cnt) {
	if(root == -1) //递归边界：空树
		return;
	inOrder(node[root].lChild, cnt);
	if(cnt > 0)
		cout << ' ';
	cnt++;
	cout << root;
	inOrder(node[root].rChild, cnt);
}

int main() {
	int N;
	cin >> N;
	char c1, c2;
	for(int i = 0; i < N; i++) {
		cin >> c1 >> c2;
		node[i].lChild = transToNum(c1);
		node[i].rChild = transToNum(c2);
	}
	int root;
	for(int i = 0; i < N; i++) { //遍历寻找根结点
		if(!notRoot[i]) { //根结点
			root = i;
			break;
		}
	}
	invertTree(root); //反转二叉树
	levelOrder(root);
	int cnt = 0;
	inOrder(root, cnt);
	return 0;
}