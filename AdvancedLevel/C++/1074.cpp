#include <iostream>
using namespace std;

struct {
	int data, next;
} node[100000]; //以地址为数组下标

int main() {
    int firstAddr, N, K, cnt = 0; //cnt 用于记录有效节点个数
    cin >> firstAddr >> N >> K;
    int addr, order[N]; //order按链表顺序存储地址
    for(int i = 0; i < N; i++) {
        cin >> addr;
        cin >> node[addr].data >> node[addr].next; //以地址为数组下标
    }
	addr = firstAddr;
    while(addr != -1) { 
        order[cnt++] = addr; //按链表顺序，记录有效结点的地址
        addr = node[addr].next;
    }
	for(int i = 0; i < cnt / K; i++) { //反转的次数
		for(int j = 0; j < K / 2; j++) { //反转
			int tmp = order[j + i * K];
			order[j + i * K] = order[K - j - 1 + i * K];
			order[K - j - 1 + i * K] = tmp;
		}
	}
    for (int i = 0; i < cnt - 1; i++)
        printf("%05d %d %05d\n", order[i], node[order[i]].data, order[i+1]);
    printf("%05d %d -1", order[cnt-1], node[order[cnt - 1]].data);
    return 0;
}