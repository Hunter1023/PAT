#include <iostream>
#include <vector>
#include <queue>
using namespace std;

int leaf[100] = {0}, layer = 0; //每层存放的叶结点个数，层数

struct {
	int layer = 1;
	vector<int> child;
} Node[100];

void BFS(int root) {
	queue<int> q;
	q.push(root); //根结点入队
	while(!q.empty()) {
		int now = q.front();
		q.pop();
		layer = max(Node[now].layer, layer);
		if(Node[now].child.size() == 0) //当前为叶结点
			leaf[Node[now].layer]++; //对应层数的叶结点数量 + 1
		for(int i = 0; i < Node[now].child.size(); i++) {
			Node[Node[now].child[i]].layer = Node[now].layer + 1;
			q.push(Node[now].child[i]);
		}
	}
}

int main() {
	int N, M, ID, K;
	cin >> N >> M;
	for(int i = 0; i < M; i++) {
		cin >> ID >> K;
		int cID; 
		for(int j = 0; j < K; j++) {
			cin >> cID;
			Node[ID].child.push_back(cID);
		}
	}
	BFS(1);
	for(int i = 1; i <= layer; i++) {
		if(i > 1)
			cout << " ";
		cout << leaf[i];
	}
	return 0;
}