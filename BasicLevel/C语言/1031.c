#include <stdio.h>

int main() {
	int weight[17] = {7, 9, 10, 5, 8, 4, 2, 1, 6, 3, 7, 9, 10, 5, 8, 4, 2}; //权重分配 
	char check[11] = "10X98765432";//校验码 
	int N, allRight = 1;//身份证的数量；身份证号码是否都正常
	char id[19];//身份证 
	scanf("%d", &N);
	while (N-- > 0) {
		scanf("%s", id);
		int sum = 0, isTrue = 1;//权重和，身份证号码是否正常
		for (int i = 0; i < 17; i++) {
			if (id[i] < '0' || id[i] > '9') {//如果前十七位不全为数字，身份证有问题 
				isTrue = 0;
				break; 
			}
			sum += (id[i] - '0') * weight[i];
		} 
		if (isTrue) {//前十七位没问题 
			if (check[sum % 11] != id[17]) {//最后一位验证码不对 
				isTrue = 0;
			}
		}
		if (!istrue) {//如果身份证有问题，输出 
			allRight = 0;
			printf("%s\n", id);	
		}
	}
	if (allRight) {
		printf("All passed\n");
	}
	return 0;
}