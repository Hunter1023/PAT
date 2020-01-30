#include <stdio.h>

int main() {
    int N;
	scanf("%d", &N); //参赛总人数
	int grades[1001] = {0}; //队伍的总分数 数组
	int group, num, score; //队伍编号，队员编号，成绩
	while (N-- > 0) {
		scanf("%d-%d %d", &group, &num, &score);
		grades[group] += score; 
	} 
	int champion = 0;
	for (int i = 0; i < 1001; i++) {
		if (grades[i] > grades[champion]) {
			champion = i;
		}
	}
	printf("%d %d\n", champion, grades[champion]);
    return 0;
}