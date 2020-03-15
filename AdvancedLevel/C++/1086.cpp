#include <iostream>
#include <stack>
using namespace std;

int pre[30], in[30], cnt = 0;

struct Node {
	int data;
	Node *lChild, *rChild;
};

Node* createTree(int preL, int preR, int inL, int inR) {
	if(preL > preR) //先序序列长度≤0时，当前二叉树不存在
		return NULL;
	Node* root = new Node; //创建一个新结点 为当前的根节点 
	root->data = pre[preL]; //后序序列的最后一个元素为根结点
	int target = inL;
	while(in[target] != pre[preL] && target <= inR) //遍历中序序列，寻找根节点
		target++;
	int leftCnt = target - inL; //左子树结点个数
	root->lChild = createTree(preL + 1, preL + leftCnt, inL, target - 1);
	root->rChild = createTree(preL + leftCnt + 1, preR, target + 1, inR);
	return root; //返回根节点
}

void postOrder(Node* root) {
	if(root == NULL)
		return;
	postOrder(root->lChild);
	postOrder(root->rChild);
	if(cnt > 0)
		cout << ' ';
	cnt++;
	cout << root->data;
}

int main() {
	int N, preIndex = 0, inIndex = 0;
	string str;
	stack<int> s;
	cin >> N;
	while(preIndex + inIndex < 2 * N) {
		cin >> str;
		if(str == "Push") { //入栈次序 相当于 先序序列
			cin >> pre[preIndex++];
			s.push(pre[preIndex-1]);
		} else { //出栈次序 相当于 中序序列
			in[inIndex++] = s.top();
			s.pop();
		}
	}
	Node* root = createTree(0, N - 1, 0, N - 1);
	postOrder(root);
	return 0;
}