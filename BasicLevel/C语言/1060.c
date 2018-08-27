/* 利用排序，简化爱丁顿数的获取 */
#include <stdio.h>
#include <stdlib.h>

int cmp(const void *a, const void *b) {
	return *(int *)b - *(int *)a;//降序 
}
int main(){
	int N;//连续骑车的天数 
	scanf("%d", &N);
	int d[N];//每天的骑车距离
	for (int i = 0; i < N; i++) {
		scanf("%d", &d[i]); 
	}
	qsort(d, N, sizeof(int), cmp);//降序排序 
	int E = 0;
	while (d[E] > E + 1 && E < N) {//如果骑行距离达标，（之前的距离必然达标） 
		E++;
	}
	printf("%d\n", E);
	return 0;
}