#include <stdio.h>

int main() {
	int N, M;//学生人数，需要查缴的种类数 
	scanf("%d %d", &N, &M);
	int num[M];//物品的编号
	for (int i = 0; i < M; i++) {
		scanf("%d", &num[i]);
	}
	char name[N][5];//姓名 
	int sum_N = 0, sum_M = 0;//问题学生的人数和问题物品总数 
	for (int i = 0; i < N; i++) {
		int K, n, isGet = 0;//个人物品数量, 编号 , 是否有查缴物品 
		scanf("%s %d", name[i], &K);
		for (int j = 0; j < K; j++) {
			scanf("%d", &n);//编号 
			for (int x = 0; x < M; x++) {
				if (num[x] == n) {
					sum_M++;
					if (!isGet) {
						printf("%s:", name[i]);
						isGet = 1;
					}
					printf(" %04d", n);
				}
			}
		}
		if (isGet) {
			sum_N++; 
			printf("\n");
		}
	}
	printf("%d %d", sum_N, sum_M);
	return 0;
}