#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

int N, M, S;
vector<int> path;

struct {
	int weight;
	vector<int> child;
} Node[100];

void DFS(int root, int sum) {
	if (Node[root].child.size() == 0) { //叶结点
		if (sum == S) {//当前路径权重和 符合要求 
			for(int i = 0; i < path.size(); i++) {
				if(i > 0)
					cout << " ";
				cout << Node[path[i]].weight;
			}
			cout << endl;
		}
		return;
	}
	if (sum > S) //剪枝
		return;
	for (int i = 0; i < Node[root].child.size(); i++) {
		int child = Node[root].child[i];
		path.push_back(child);
		DFS(Node[root].child[i], sum + Node[child].weight);
		path.pop_back();
	}
}

bool cmp(int a, int b) { //按权值降序
	return Node[a].weight > Node[b].weight;
}

int main() {
	cin >> N >> M >> S;
	for (int i = 0; i < N; i++)
		cin >> Node[i].weight;
	int ID, K, index;
	for (int i = 0; i < M; i++) {
		cin >> ID >> K;
		for (int j = 0; j < K; j++) {
			cin >> index;
			Node[ID].child.push_back(index);
		}
		//将孩子结点按权值降序排序，使得之后遍历路径时也是降序
		sort(Node[ID].child.begin(), Node[ID].child.end(), cmp);
	}
	path.push_back(0);
	DFS(0, Node[0].weight);
	return 0;
}