#include <iostream>
#include <queue>
using namespace std;

int post[30], in[30]; //创建后序、中序序列

struct Node {
	int data;
	Node *lChild, *rChild;
};

Node* createTree(int postL, int postR, int inL, int inR) {
	if(postL > postR) //后序序列长度≤0时，当前二叉树不存在
		return NULL;
	Node* root = new Node; //创建一个新结点 为当前的根节点 
	root->data = post[postR]; //后序序列的最后一个元素为根结点
	int target = inL;
	while(in[target] != post[postR] && target <= inR)  //遍历中序序列，寻找根节点
		target++;
	int leftCnt = target - inL; //左子树结点个数
	root->lChild = createTree(postL, postL + leftCnt - 1, inL, target - 1);
	root->rChild = createTree(postL + leftCnt, postR - 1, target + 1, inR);
	return root; //返回根节点
}

void layerOrder(Node* root) { //层序遍历
	queue<Node*> q;
	q.push(root);
	int cnt = 0;
	while(!q.empty()) {
		Node* now = q.front(); //取出队首元素
		q.pop(); //队首元素出队
		if(cnt > 0) //不是第一个元素
			cout << ' ';
		cout << now->data;
		cnt++;
		if(now->lChild != NULL) //子树非空则入队
			q.push(now->lChild);
		if(now->rChild != NULL)
			q.push(now->rChild);
	}
	cout << endl;
}

int main() {
	int N;
	cin >> N;
	for(int i = 0; i < N; i++)
		cin >> post[i];
	for(int i = 0; i < N; i++)
		cin >> in[i];
	Node* root = createTree(0, N - 1, 0, N - 1); //根据后序和中序序列确定二叉树
	layerOrder(root); //层序遍历
	return 0;
}