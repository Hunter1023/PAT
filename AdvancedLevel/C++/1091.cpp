#include <iostream>
#include <queue>
using namespace std;

int M, N, L, T;
//按 前后左右上下 顺序，设定相对当前位置的增量
const int X[6] = {-1, 1, 0, 0, 0, 0};
const int Y[6] = {0, 0, -1, 1, 0, 0};
const int Z[6] = {0, 0, 0, 0, -1, 1};
int MRI[1286][128][60], inq[1286][128][60] = {0}; //各点情况，各点是否入过队

typedef struct Node {
	int x, y, z;
} Node;

bool judge(int x, int y, int z) { //判断当前位置是否需要访问
	if(x < 0 || x >= M || y < 0 || y >= N || z < 0 || z >= L) //越界
		return false;
	if(MRI[x][y][z] == 0 || inq[x][y][z] == 1) //当前位置为0 或 已入过队
		return false;
	return true;
}

int BFS(int x, int y, int z) {
	int cnt = 1; //present core's volume
	Node node = {x, y, z};
	queue<Node> q;
	q.push(node); //当前结点的副本入队
	inq[x][y][z] = 1; //标记当前结点已入队
	while(!q.empty()) {
		Node top = q.front(); //获取队首元素
		q.pop(); //队首元素出队
		for(int i = 0; i < 6; i++) { //获取6个相邻位置
			node.x = top.x + X[i];
			node.y = top.y + Y[i];
			node.z = top.z + Z[i];
			if(judge(node.x, node.y, node.z)) { //新位置需要访问
				cnt++;
				q.push(node);
				inq[node.x][node.y][node.z] = 1;
			}
		}
	}
	return cnt;
}

int main() {
	cin >> M >> N >> L >> T;
	for(int z = 0; z < L; z++)
		for(int x = 0; x < M; x++) 
			for(int y = 0; y < N; y++)
				cin >> MRI[x][y][z];
	int volume = 0; //total stroke core's volume
	for(int z = 0; z < L; z++) { //枚举每个位置
		for(int x = 0; x < M; x++) {
			for(int y = 0; y < N; y++) {
				int cnt = 0; // present core's volume
				if(MRI[x][y][z] == 1 && inq[x][y][z] == 0) { //元素为1且未入过队
					cnt = BFS(x, y, z);
					if(cnt >= T)
						volume += cnt;
				}
			}
		}
	}
	cout << volume << endl;
	return 0;
}