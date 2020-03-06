#include <stdio.h>

int main() {
	int N, K, grades[101] = {0}, score;//学生人数，要查询的分数个数, 统计各分数的人数 
	scanf("%d", &N);
	for (int i = 0; i < N; i++) {
		scanf("%d", &score);
		grades[score]++;
	}
	scanf("%d", &K);
	for (int i = 0; i < K; i++) {
		scanf("%d", &score); //要查找的分数 
		if (i != 0)
			printf(" ");
		printf("%d", grades[score]);
	}
	return 0;
}