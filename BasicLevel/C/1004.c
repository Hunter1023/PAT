#include <stdio.h>
#include <string.h>

int main() {
	char max_name[11], min_name[11], name[11], max_num[11], min_num[11], num[11];//创建姓名和字符串数组 
	int max = -1, min = 101, score = 0, cnt = 0;//初始化分数 和 输入的行数 
	scanf("%d", &cnt);
	for(int i = 0; i < cnt; i++) {
		scanf("%s %s %d", name, num, &score);
		if (score > max) {//如果成绩比最高分高，复制对应的信息 
			strcpy(max_name, name);
			strcpy(max_num, num);
			max = score;
		} 
		if (score < min) {
			strcpy(min_name, name);
			strcpy(min_num, num);
			min = score;
		}
	}
	printf("%s %s\n%s %s\n", max_name, max_num, min_name, min_num);
	return 0;
} 