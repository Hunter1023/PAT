/* 将数组下标作为学校编号，累加成绩 */
#include <cstdio>

int main() {
	int N, id, grades; //参数人数, 学校编号, 成绩
	scanf("%d", &N);
	int school[N+1] = {0}; //数组初始化
	for (int i = 0; i < N; i++) {
		scanf("%d %d", &id, &grades);
		school[id] += grades;
	}
	int maxId, maxSum = -1; //得分最高的学校编号、总分
	for (int i = 1; i <= N; i++) {//最多有N个学校
		if (school[i] > maxSum) {
			maxId = i;
			maxSum = school[i];
		}
	}
	printf("%d %d", maxId, maxSum);
	return 0;
}