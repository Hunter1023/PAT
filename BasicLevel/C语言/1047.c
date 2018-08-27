/* 能否优化找出最高分的冠军的方式 */
#include <stdio.h>

int main() {
    int N;
	scanf("%d", &N);//参赛总人数
	int grades[1001] = {0};//队伍的总分数 数组 ，队伍最多1000支
	while (N-- > 0) {
		int group, num, score;//队伍编号，队员编号，成绩
		scanf("%d-%d %d", &group, &num, &score);
		grades[group] += score; 
	} 
	int champion = 0, score = 0;
	for (int i = 1; i < 1001; i++) {
		if (grades[i] > score) {
			champion = i;
			score = grades[i];
		}
	}
	printf("%d %d\n", champion, score);
    return 0;
}