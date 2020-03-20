#include <iostream>
#include <algorithm>
using namespace std;

int N, M, K, city1, city2;
int G[1001][1001] = {0}, vis[1001] = {0};

void DFS(int city) {
	vis[city] = 1; //已访问当前城市
	for(int i = 1; i <= N; i++) {
		if(!vis[i] && G[city][i] == 1) //未访问过 且 城市之间有公路
			DFS(i);
	}
}

int main() {
	scanf("%d %d %d", &N, &M, &K);
	for(int i = 0; i < M; i++) {
		scanf("%d %d", &city1, &city2);
		G[city1][city2] = G[city2][city1] = 1;
	}
	while(K--) {
		fill(vis + 1, vis + N + 1, 0); //每次需要重置城市的访问状态
		scanf("%d", &city1); //读入失去的城市
		vis[city1] = 1; //标记失去的城市为已访问
		int cnt = 0; //连通分量个数
		for(int i = 1; i <= N; i++) { //遍历图，查询连通分量个数
			if(!vis[i]) { //当前城市 未失去 且 未被访问过
				cnt++;
				DFS(i);
			}
		}
		printf("%d\n", cnt - 1);
	}
	return 0;
}