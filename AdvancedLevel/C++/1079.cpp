#include <iostream>
#include <vector>
#include <queue>
using namespace std;

struct {
	int saleCnt = 0;
	double price = 0;
	vector<int> child;
} Node[100000];

double totalSales(double price, double rate) {
	double total = 0;
	queue<int> q;
	q.push(0);
	Node[0].price = price;
	while(!q.empty()) {
		int now = q.front();
		q.pop();
		if(Node[now].saleCnt > 0)
			total += Node[now].saleCnt * Node[now].price;
		for(int i = 0; i < Node[now].child.size(); i++) {
			Node[Node[now].child[i]].price = Node[now].price * (1 + rate);
			q.push(Node[now].child[i]);
		}
	}
	return total;
}

int main() {
	int N;
	double P, r;
	cin >> N >> P >> r;
	r /= 100;
	for(int i = 0; i < N; i++) {
		int cnt; //下一级经销商的个数
		cin >> cnt; 
		if(cnt == 0) { //是零售商
			cin >> Node[i].saleCnt; //记录销量
		} else {
			int num;
			for(int j = 0; j < cnt; j++) {
				cin >> num;
				Node[i].child.push_back(num);
			}
		}
	}
	printf("%.1f\n", totalSales(P, r));
	return 0;
}