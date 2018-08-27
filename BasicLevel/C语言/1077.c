/* 去掉无效评分之后，记得去掉最高分和最低分 */
#include <stdio.h>
#include <stdlib.h>
#include <math.h>

int cmp(const void *a, const void *b) {//升序 
	return *(int *)a > *(int *)b;
}
int main() {
	int N, M;//分组数，满分
	scanf("%d %d", &N, &M); 
	int G2, grades[N-1];//老师评分和 其他组的评分 
	for (int i = 0; i < N; i++) {
		scanf("%d", &G2);
		for (int j = 0; j < N - 1; j++) {
			scanf("%d", &grades[j]);
		}
		qsort(grades, N-1, sizeof(int), cmp);
		int start = 0, end = N - 1; 
		double G1 = 0.0;
		for (int i = 0; i < N - 1; i++) {
			if (grades[i] < 0) {
				start++;
			} else if (grades[i] > M) {
				end = i;
				break;
			}
		} 
		for (int i = start + 1; i < end - 1; i++) {//去掉一个最低分，去掉一个最高分 
			G1 += grades[i];
		}
		G1 = G1/(end - start - 2);
		int result = round((G1 + G2) / 2);
		printf("%d\n", result);
	}
	return 0;
}