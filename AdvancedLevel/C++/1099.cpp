#include <iostream>
#include <algorithm>
#include <queue>
using namespace std;

int N, num[100], index = 0;

struct {
	int data = -1, lChild, rChild;
} Node[100];

void inOrder(int root) {
	if(root == -1)
		return;
	inOrder(Node[root].lChild);
	Node[root].data = num[index++];
	inOrder(Node[root].rChild);
}

void levelOrder(int root) {
	queue<int> q;
	q.push(root);
	index = 0;
	while(!q.empty()) {
		int now = q.front();
		q.pop();
		if(index > 0)
			cout << ' ';
		index++;
		cout << Node[now].data;
		if(Node[now].lChild != -1)
			q.push(Node[now].lChild);
		if(Node[now].rChild != -1)
			q.push(Node[now].rChild);
	}
}

int main() {
	cin >> N;
	for(int i = 0; i < N; i++)
		cin >> Node[i].lChild >> Node[i].rChild;
	for(int i = 0; i < N; i++)
		cin >> num[i];
	sort(num, num + N);
	inOrder(0);
	levelOrder(0);
	return 0;
}