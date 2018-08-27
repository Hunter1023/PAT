/* 抓住题目的核心要求 返回指定分数的人数，因此用分数为下标的数组存储人数最合适。 */
#include <stdio.h>

int main() {
	int N, K;//学生人数，要查询的分数个数 
	scanf("%d", &N);
	int grades[101] = {0};//统计各分数的人数 
	for (int i = 0; i < N; i++) {
		int score; 
		scanf("%d", &score);
		grades[score]++;
	}
	scanf("%d", &K);
	int search[K];//要查找的分数 
	for (int i = 0; i < K; i++) {
		scanf("%d", &search[i]);
	}
	int i;
	for (i = 0; i < K - 1; i++) {//查找指定分数的人数 
		printf("%d ", grades[search[i]]);
	}
	printf("%d", grades[search[i]]);
	return 0;
}