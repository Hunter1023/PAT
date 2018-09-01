/* 也可采用 将字符作为数组下标的方式统计数量 */
#include <stdio.h>
#include <string.h>

int main() {
	char line1[1001], line2[1001];
	scanf("%s\n%s", line1, line2);
	for (int i = 0; i < strlen(line1); i++) { //遍历两串珠子，符合要求的珠子都标注掉 
		for (int j = 0; j < strlen(line2); j++) {
			if (line1[i] == line2[j]) {
				line1[i] = '*';
				line2[j] = '*';
			}
		}
	}
	int lack = 0, surplus = 0;
	for (int i = 0; i < strlen(line2); i++) {//有想要的珠子，统计数量 
    	if (line2[i] != '*') { 
    		lack++;
		}
	}
    if (lack > 0) {
		printf("No %d\n", lack);
	} else {
		for (int i = 0; i < strlen(line1); i++) {//有多余的珠子，统计数量 
    		if (line1[i] != '*') {
    			surplus++;
			}
		}
		printf("Yes %d\n", surplus);
	}
	return 0;
}