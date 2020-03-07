#include <stdio.h>

int main() {
    int N;
	scanf("%d", &N); //参赛总人数
	int grades[1001] = {0}; //队伍的总分数 数组
	int group, num, score; //队伍编号，队员编号，成绩
	while(N--) {
		scanf("%d-%d %d", &group, &num, &score);
		grades[group] += score; 
	} 
	int max = 1;
	for(int i = 2; i <= 1000; i++) {
		if(grades[i] > grades[max])
			max = i;
	}
	printf("%d %d\n", max, grades[max]);
    return 0;
}