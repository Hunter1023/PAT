#include <iostream>
#include <algorithm>
using namespace std;

const int INF = 1e9, MAXV = 500;
int N, M, st, ed; //城市数，边数，起点，终点
int G[MAXV][MAXV], weight[MAXV]; //邻接矩阵表示图, 点权
int d[MAXV], w[MAXV], cnt[MAXV], vis[MAXV] = {0}; //最短距离，最大点权和，最短路径条数，是否已访问

void dijkstra(int st) {
	d[st] = 0; //到自身的最短距离为0
	w[st] = weight[st]; //最大点权和初始化为 当前城市的救援数量
	cnt[st] = 1; //最短路径数
	for(int i = 0; i < N; i++) {
		int u = -1, MIN = INF; //u使d[u]最小，MIN存放最小的d[u]
		for(int j = 0; j < N; j++) { //找到未访问的顶点中 d[] 最小的
			if(!vis[j] && d[j] < MIN) {
				u = j;
				MIN = d[j];
			}
		}
		if(u == -1) //找不到小于INF的d[u]，说明剩下的顶点和起点begin不连通
			return;
		vis[u] = 1; //标记u为已访问
		for(int v = 0; v < N; v++) { 
			if(!vis[v] && G[u][v] != INF) { //v未访问 且 u能到达v
				if(d[u] + G[u][v] < d[v]) {
					d[v] = d[u] + G[u][v];
					w[v] = w[u] + weight[v];
					cnt[v] = cnt[u]; //覆盖最短路径数量 
				} else if(d[u] + G[u][v] == d[v]) {
					if(w[u] + weight[v] > w[v])
						w[v] = w[u] + weight[v];
					cnt[v] += cnt[u]; //更新最短路径条数
				}
			}
		}
	}
}

int main() {
	cin >> N >> M >> st >> ed;
	for(int i = 0; i < N; i++)
		cin >> weight[i]; //获取当前城市救援队数量
	fill(G[0], G[0] + MAXV * MAXV, INF); //初始化图
	fill(d, d + MAXV, INF); //初始化最短距离
	fill(cnt, cnt + MAXV, 0); //初始化最短路径数量
	fill(w, w + MAXV, 0); //初始化最大点权和
	int c1, c2;
	for(int i = 0; i < M; i++) { //初始化图中的边
		cin >> c1 >> c2;
		cin >> G[c1][c2];
		G[c2][c1] = G[c1][c2];
	}
	dijkstra(st); //迪杰斯特拉算法求解单源最短路径
	cout << cnt[ed] << " " << w[ed] << endl; //输出最短路径数量和最大点权和
	return 0;
}