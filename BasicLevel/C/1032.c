/* 将数组下标作为学校编号，累加成绩 */
#include <stdio.h>

int main() {
	int N; //参赛人数
	scanf("%d", &N);
	int player[N];
	for (int i = 0; i < N; i++) {//初始化 
		player[i] = 0;
	}
	for (int i = 0; i < N; i++) {
		int index, grades;
		scanf("%d %d", &index, &grades);
		player[index-1] += grades;
	}
	int max_index, max = 0;
	for (int i = 0; i < N; i++) {
		if (player[i] > max) {
			max_index = i + 1;
			max = player[i];
		}
	}
	printf("%d %d\n", max_index, max);
	return 0;
}