#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

const int MAXV = 500, INF = 1e9;

int N, M, S, D;
vector<int> pre[MAXV], path, tmpPath; //最短路径上结点的前驱结点, 最短路径，临时最短路径
int G[MAXV][MAXV], cost[MAXV][MAXV]; //记录距离和开销的图
int dis[MAXV], minCost = INF,  vis[MAXV] = {0}; //到其余顶点的最短距离，最低开销, 是否已访问

void dijkstra(int S) { //用dijkstra算法求源点到其余顶点的最短路径
	fill(dis, dis + MAXV, INF); //初始化最短距离
	dis[S] = 0; //到自身的最短距离为0
	for(int i = 0; i < N; i++) {
		int u = -1, MIN = INF; //u使d[u]最小，MIN存放最小的d[u]
		for(int j = 0; j < N; j++) {  //找到未访问的顶点中 d[] 最小的
			if(!vis[j] && dis[j] < MIN) {
				u = j;
				MIN = dis[j];
			}
		}
		if(u == -1) //找不到小于INF的d[u]，剩余顶点和起点不连通
			return;
		vis[u] = 1; //标记u为已访问
		for(int v = 0; v < N; v++) { //优化到其余顶点的最短路径
			if(!vis[v] && G[u][v] != INF) { //未访问过且能到达
				if(dis[u] + G[u][v] < dis[v]) { //路径更短
					dis[v] = dis[u] + G[u][v]; //更新路径长度
					pre[v].clear(); //清空旧的最短路径的前驱结点
					pre[v].push_back(u); //更新u为到达v的最短路径的前驱
				} else if(dis[u] + G[u][v] == dis[v]) {
					pre[v].push_back(u); //增加新的最短路径方案
				}
			}
		}
	}
}

void DFS(int v) { //v为当前结点
	if(v == S) { //递归边界
		tmpPath.push_back(v); //将起点加入临时路径
		int tmpCost = 0; //记录当前路径花费总和
		for(int i = tmpPath.size() - 1; i > 0; i--) { //倒着访问
			int id = tmpPath[i], idNext = tmpPath[i-1];
			tmpCost += cost[id][idNext];
		}
		if(tmpCost < minCost) { //开销更少
			minCost = tmpCost;
			path = tmpPath; //更新最短路径
		}
		tmpPath.pop_back(); //体现递归的特点
		return;
	}
	//递归调用
	tmpPath.push_back(v);
	for(int i = 0; i < pre[v].size(); i++)
		DFS(pre[v][i]);
	tmpPath.pop_back(); //注入递归灵魂
}

int main() {
	cin >> N >> M >> S >> D;
	int c1, c2;
	fill(G[0], G[0] + MAXV * MAXV, INF); //初始化图
	fill(cost[0], cost[0] + MAXV, INF);
	for(int i = 0; i < M; i++) {
		cin >> c1 >> c2;
		cin >> G[c1][c2] >> cost[c1][c2];
		G[c2][c1] = G[c1][c2];
		cost[c2][c1] = cost[c1][c2];
	}
	dijkstra(S);
	DFS(D);
	for(int i = path.size() - 1; i >= 0; i--) //输出最短路径经过的城市
		cout << path[i] << " ";
	cout << dis[D] << " " << minCost << endl; //输出最短路径长度和最小开销
	
	return 0;
}