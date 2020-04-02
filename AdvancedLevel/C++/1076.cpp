#include <iostream>
#include <vector>
#include <algorithm>
#include <queue>
using namespace std;

struct Node {
	int id;
	int layer; //结点层号
};

vector<Node> adj[1001]; //邻接表
int inQ[1001] = {0}; //结点是否已加入过队列

int BFS(int startId, int L) { //起始结点，转发层数上限
	int numForward = 0; //转发数
	queue<Node> q;
	Node start = {startId, 0}; //定义起始结点
	q.push(start);
	inQ[startId] = 1;
	while(!q.empty()) {
		Node topNode = q.front(); //取出队首元素
		q.pop();
		int id = topNode.id;
		for(int i = 0; i < adj[id].size(); i++) {
			Node next = adj[id][i];
			next.layer = topNode.layer + 1;
			if(inQ[next.id] == 0 && next.layer <= L) {
				q.push(next); //将next入队
				inQ[next.id] = 1;
				numForward++; //转发数 + 1
			}
		}
	}
	return numForward;
}

int main() {
	Node user;
	int N, L, cntFollow, idFollow;
	cin >> N >> L;
	for(int i = 1; i <= N; i++) {
		user.id = i;
		cin >> cntFollow; //关注的人数
		for(int j = 0; j < cntFollow; j++) {
			cin >> idFollow;
			adj[idFollow].push_back(user); //建立关注者与被关注者的连接
		}
	}
	int K, startId;
	cin >> K; //查询个数
	for(int i = 0; i < K; i++) {
		fill(inQ, inQ + 1001, 0);
		cin >> startId;
		int layer = BFS(startId, L); //返回转发层数
		cout << layer << endl;
	}
	return 0;
}