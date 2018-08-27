/*
 * 1. 通过数组下标来表示下标，便于排序
 * 2. 考虑存在无效节点的情况
 */
#include <stdio.h>

typedef struct {
	int address;//节点地址
	int data; //整数数据
	int next;//下一节点的地址  
} Node; 
int main() {
	int addr, N, K;//读取首地址，节点数量，反转个数 
	scanf("%d %d %d", &addr, &N, &K);
	Node *origin = (Node *)malloc(sizeof(Node) * 100001);//创建初始单链表,反转后的单链表 
	Node *sort = (Node *)malloc(sizeof(Node) * 100001);
	for (int i = 0; i < N; i++) {//读取节点
		Node temp; 
		scanf("%d %d %d", &temp.address, &temp.data, &temp.next);
		origin[temp.address] = temp;
	}
	for (int i = 0; i < N; i++) {//排序 
		sort[i] = origin[addr];
		addr = sort[i].next;
		if (addr == -1) {
			N = i + 1;//可能有无效的节点，需要更新链表中节点的数量 
			break;
		}
	} 	
	for (int i = 0; i < N / K; i++) {//反转 
		for (int j = 0; j < K / 2; j++) {
			Node temp;
			temp = sort[j+i*K];
			sort[j+i*K] = sort[K-1-j+i*K];
			sort[K-1-j+i*K] = temp;
		}
	}
	for (int i = 0; i < N; i++) {
		if(i != N - 1) {
			sort[i].next = sort[i+1].address;
			printf("%05d %d %05d\n", sort[i].address, sort[i].data, sort[i].next);
		} else {
			sort[i].next = -1;
			printf("%05d %d %d\n", sort[i].address, sort[i].data, sort[i].next);
		}
	} 
	return 0;
}