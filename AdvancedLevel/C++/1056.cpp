#include <iostream>
#include <cmath>
#include <queue>
using namespace std;

typedef struct {
	int weight, rank;
} mouse;

int main() {
	int N_P, N_G, order; //总数，每组的最大容量, 序号
	cin >> N_P >> N_G;
	mouse m[N_P];
	for(int i = 0; i < N_P; i++) //顺序获取老鼠的重量
		cin >> m[i].weight;
	queue<int> q;
	for(int i = 0; i < N_P; i++) { //获取序号
		cin >> order;
		q.push(order); //将序号入队
	}
	int tmp = N_P, group; //当前轮的 总老鼠数 和 组数
	while(q.size() != 1) { //未决出冠军
		group = ceil((double)tmp / N_G);
		for(int i = 0; i < group; i++) {
			int max = q.front(); //初始化最肥老鼠的下标
			for(int j = 0; i * N_G + j < tmp && j < N_G; j++) { //遍历组中老鼠
				int front = q.front(); //队首老鼠的序号
				if(m[front].weight > m[max].weight) //找出最肥的老鼠
					max = front;
				m[front].rank = group + 1; //该轮老鼠排名
				q.pop(); //依次出队
			}
			q.push(max); //最肥的老鼠晋级
		}
		tmp = group; //更新新一轮的总数
	}
	m[q.front()].rank = 1;
	for(int i = 0; i < N_P; i++) {
		if(i > 0)
			cout << ' ';
		cout << m[i].rank;
	}
	return 0;
}