#include <iostream>
using namespace std;

struct {
	char data;
	int next, flag; //是否位于第一条链表中
} node[100000];

int main() {
	int s1, s2, N, addr;
	cin >> s1 >> s2 >> N;
	for(int i = 0; i < N; i++) {
		cin >> addr;
		cin >> node[addr].data >> node[addr].next;
		node[addr].flag = 0; //初始化不在第一条链表中
	}
	while(s1 != -1) {
		node[s1].flag = 1; //标记位第一条链表中
		s1 = node[s1].next;
	}
	while(s2 != -1) {
		if(node[s2].flag == 1) { //也位于第二条链表
			printf("%05d\n", s2);
			break;
		}
		s2 = node[s2].next;
	}
	if(s2 == -1) //没有共同结点
		printf("-1\n");
	return 0;
}