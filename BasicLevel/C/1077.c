/* 去掉无效评分之后，记得去掉最高分和最低分 */
#include <stdio.h>
#include <math.h>

int main() {
	int N, M;//分组数
	scanf("%d %d", &N, &M); 
	for (int i = 0; i < N; i++) {
		double G1 = 0.0;//总分
		int G2, max = -1, min = M + 1, cnt = 0, grades;//老师评分，最高分和最低分，有效分数个数，有效分数数量 
		scanf("%d", &G2);
		for (int j = 0; j < N - 1; j++) {
			scanf("%d", &grades);
			if (grades >= 0 && grades <= M) {
				cnt++; 
				G1 += grades;
				if (grades > max) {
					max = grades;
				} 
				if (grades < min) {
					min = grades;
				}
			}
		}
		G1 = (G1 - min - max) / (cnt - 2);
		printf("%d\n", (int)round((G1 + G2) / 2));
	}
	return 0;
}