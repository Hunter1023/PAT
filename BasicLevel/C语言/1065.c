/* 待优化 */
#include <stdio.h>
#include <stdlib.h>

int main() {
	int N, M;//伴侣的对数，派对总人数 
	scanf("%d", &N);
	int cp[100000];//记录情侣情况
	for(int i = 0; i < 100000; i++) {
		cp[i] = -1;
	}
	int a, b;
	for (int i = 0; i < N; i++) {//读取N行情侣的id 
		scanf("%d %d", &a, &b);
		cp[a] = b;//记录id对应的情侣id 
		cp[b] = a;
	}
	scanf("%d", &M);
	int all[M], cnt_dog = 0;//所有人员的id，单身狗的数量 
	for (int i = 0; i < M; i++) {//读取所有人的id 
		scanf("%d", &all[i]);
		if (cp[all[i]] == -1) {//如果没有对象 
			cnt_dog++;
			cp[all[i]] = -3;
		} else {//如果有对象，将值设为-2，表示自己参加 
			cp[all[i]] = -2; 
		} 
	}
	for(int i = 0; i < 100000; i++) {
		if (cp[i] > -1 && cp[cp[i]] == -2) {//自己没参加，对象参加 
			cnt_dog++; 
			cp[cp[i]] = -3;//改为单身狗状态 
		}
	} 
	printf("%d\n", cnt_dog);
	for (int i = 0; i < 100000 && cnt_dog > 0; i++) {
		if (cp[i] == -3) {
			printf("%05d", i);
			if (cnt_dog != 1) {
				printf(" ");
			}
			cnt_dog--;
		}
	}
	return 0;
}