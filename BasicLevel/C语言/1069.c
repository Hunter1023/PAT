/* 看能否再优化 */
#include <stdio.h>
#include <string.h>

int isGot(int *isWin, int length, int j, char name[][21]) {
	for (int i = 0; i < length; i++) {
		if (isWin[i] != 0 && !strcmp(name[i], name[j])) {
			return 1;
		}
	}
	return 0;
}
int main() {
	int M, N, S;//转发总量，抽奖间隔，第一位中奖的序号（编号1开始
	scanf("%d %d %d", &M, &N, &S); 
	char name[M][21];
	int isWin[M], cnt = 0;//是否中奖，中奖人数的统计 
	for (int i = 0; i < M; i++) {
		scanf("%s", name[i]);
		isWin[i] = 0;
	}
	for (int i = S - 1; i < M; i += N) {
		while (isGot(isWin, M, i, name)) {//已中奖则跳过 
			i++;
		}
		if (i < M) {
			printf("%s\n", name[i]);
			cnt++; 
			isWin[i] = 1; 
		}
	}
	if(cnt == 0) {
		printf("Keep going...\n");
	}
	return 0;
}