/*
 * 1. 分析可知，绳子的对折使 长度指数递减，自然 越长的绳子越迟串联，即可得到最大长度 —— qsort() 排序
 * 2. 向下取整
 *	2.1 方式一：直接将double型转为int型，即去除小数
 *	2.2 方式二：floor()函数
 */
#include <stdio.h>
#include <stdlib.h>

int cmp(const void *a, const void *b) {//升序 
	return *(double *)a > *(double *)b; 
}
int main() {
	int N;//绳子的数量
	scanf("%d", &N);
	double len[N], length;//每段绳子的长度，最后绳子的长度 
	for (int i = 0; i < N; i++) {
		scanf("%lf", &len[i]);
	}
	qsort(len, N, sizeof(double), cmp);
	length = len[0];
	for(int i = 1; i < N; i++) {
		length = length / 2 + len[i] / 2;
	}
	printf("%d\n", (int)length);
	return 0;
}