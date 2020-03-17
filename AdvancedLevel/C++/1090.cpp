#include <iostream>
#include <vector>
using namespace std;

double maxP = -1, r;
int maxCnt = 0;
vector<int> child[100000];

void DFS(int root, double price) {
	if(child[root].size() == 0) { //零售商
		if(price > maxP) {
			maxP = price;
			maxCnt = 1;
		} else if(price == maxP) {
			maxCnt++;
		}
		return;
	}
	for(int i = 0; i < child[root].size(); i++)
		DFS(child[root][i], price * (1 + r));
}

int main() {
	int N;
	double P;
	cin >> N >> P >> r;
	r /= 100;
	int root, S_i;
	for(int i = 0; i < N; i++) {
		cin >> S_i;
		if(S_i == -1) { //present is root supplier
			root = i;
		} else {
			child[S_i].push_back(i);
		}
	}
	DFS(root, P);
	printf("%.2f %d\n", maxP, maxCnt);
	return 0;
}