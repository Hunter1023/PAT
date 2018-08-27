/*
 * （根据1025出的题）待优化
 * 1. 通过数组下标表示节点地址
 * 2. 存在无效节点
 */
#include <stdio.h>

typedef struct {
	int addr;
	int data;
	int next;	
} Node;
int main() {
    int firstAddr, N, K, minus_cnt = 0, cnt_K = 0;//第一个节点的地址，节点总数，正整数K ,负数的数量 
	scanf("%d %d %d", &firstAddr, &N, &K); 
    Node nodes[100001];//下标为节点地址 
    int addr; 
    for (int i = 0; i < N; i++) {
    	scanf("%d ", &addr);
    	scanf("%d %d", &nodes[addr].data, &nodes[addr].next);
    	if (nodes[addr].data < 0) {//统计负数数量 
    		minus_cnt++;
		} else if (nodes[addr].data >= 0 && nodes[addr].data <= K) {//统计 [0, K] 区间内的元素数量 
			cnt_K++;
		}
	}
	Node newNodes[N];//节点总数 
	addr = firstAddr;
	int i= 0;
	while (addr != -1 && minus_cnt != 0) {//遍历链表
		if (nodes[addr].data < 0) {//如果是负数 
			newNodes[i].addr = addr;
			newNodes[i].data = nodes[addr].data;
			i++;
			minus_cnt--;
		} 
		addr = nodes[addr].next;
	}
	addr = firstAddr;
	while (addr != -1 && cnt_K != 0) {//遍历链表
		if (nodes[addr].data >= 0 && nodes[addr].data <= K) {
			newNodes[i].addr = addr;
			newNodes[i].data = nodes[addr].data;
			i++;
			cnt_K--; 
		} 
		addr = nodes[addr].next;
	}
	addr = firstAddr;
	while (addr != -1 && i != N) {//遍历链表
		if (nodes[addr].data > K) {
			newNodes[i].addr = addr;
			newNodes[i].data = nodes[addr].data;
			i++;
		} 
		addr = nodes[addr].next;
	}
	newNodes[i].addr = -1;
	for (int j = 0; j < N; j++) {
		printf("%05d %d ", newNodes[j].addr, newNodes[j].data);
		if (newNodes[j+1].addr != -1) {
			printf("%05d\n", newNodes[j+1].addr);
		} else {
			printf("-1\n");
			break;
		}
	}
    return 0;
}