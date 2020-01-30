#include <stdio.h>

int main() {
	int nums[10] = {0};//记录各个数字的个数
	for (int i = 0; i < 10; i++) {
		scanf("%d", &nums[i]);
	} 
	for (int i = 1; i < 10; i++) {//遍历从数字1开始的数字个数 
		if (nums[i] != 0) {//如果不是0，作为最小数字的开头数字 
			printf("%d", i);
			nums[i]--;
			break; 
		} 
	}
	for (int i = 0; i < 10; i++) {//从0开始遍历 
		while(nums[i] > 0) {
			printf("%d", i);
			nums[i]--;
		} 
	}
	return 0;
}