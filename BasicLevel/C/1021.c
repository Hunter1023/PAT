#include <stdio.h>

int main() {
	int nums[10] = {0};//用于统计各数字出现的次数
	char num;
	while ((num = getchar()) != '\n') {
		nums[num-'0']++;
	}
	for (int i = 0; i < 10; i++) {
		if (nums[i] != 0) {
			printf("%d:%d\n", i, nums[i]);
		}
	}
	return 0;
}