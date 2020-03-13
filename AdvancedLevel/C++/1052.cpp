#include <iostream>
#include <algorithm>
using namespace std;

struct Node {
	int key, addr, next, flag = 0;
} node[100000];

bool cmp(Node n1, Node n2) {
	if(n1.flag != n2.flag) {
		return n1.flag > n2.flag;
	} else {
		return n1.key < n2.key;
	}
}

int main() {
	int N, headAddr, addr, cnt = 0;
	cin >> N >> headAddr;
	for(int i = 0; i < N; i++) {
		cin >> addr;
		node[addr].addr = addr;
		cin >> node[addr].key >> node[addr].next;
	}
	addr = headAddr;
	while(addr != -1) {//标记位于链表的结点
		node[addr].flag = 1; 
		addr = node[addr].next;
		cnt++; //统计有效结点数量
	}
	if(cnt == 0) {
		printf("0 -1\n");
	} else {
		sort(node, node + 100000, cmp);
		printf("%d %05d\n", cnt, node[0].addr);
		for(int i = 0; i < cnt; i++) {
			printf("%05d %d ", node[i].addr, node[i].key);
			if(i != cnt - 1) {
				printf("%05d\n", node[i+1].addr);
			} else {
				printf("-1\n");
			}
		}
	}
	return 0;
}