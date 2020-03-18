#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

int N, index = 0;
vector<int> level, num; //CBST按照层序存放结点

void inOrder(int root) { //中序遍历二叉树
	if(root > N) //空结点
		return;
	inOrder(root * 2); //递归左子树
	level[root] = num[index++]; //按中序顺序填入元素
	inOrder(root * 2 + 1); //递归右子树
}

int main() {
	cin >> N;
	num.resize(N);
	level.resize(N+1);
	for(int i = 0; i < N; i++)
		cin >> num[i];
	sort(num.begin(), num.end()); //升序排序，获得中序遍历序列
	inOrder(1);
	for(int i = 1; i <= N; i++) {
		if(i > 1)
			cout << " ";
		cout << level[i];
	}
	return 0;
}