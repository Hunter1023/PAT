#include <stdio.h>

int main() {
	int weight[17] = {7, 9, 10, 5, 8, 4, 2, 1, 6, 3, 7, 9, 10, 5, 8, 4, 2}; //权重分配 
	char check[11] = "10X98765432";//校验码 
	int N, cnt_false = 0;//身份证的数量；有问题身份证的数量 
	char id[18];//身份证 
	scanf("%d", &N);
	while (N-- > 0) {
		scanf("%s", id);
		int sum = 0, istrue = 1;//权重和； 判断身份证是否有问题
		for (int i = 0; i < 17; i++) {
			sum += (id[i] - '0') * weight[i];
			if (id[i] < '0' || id[i] > '9') {//如果前十七位不全为数字，身份证有问题 
				istrue = 0;
				cnt_false++; 
				break; 
			}
		} 
		if (istrue) {//前十七位没问题 
			if (check[sum % 11] != id[17]) {//最后一位验证码不对 
				istrue = 0;
				cnt_false++;
			}
		}
		if (!istrue) {//如果身份证有问题，输出 
			printf("%s\n", id);	
		}
	}
	if (cnt_false == 0) {
		printf("All passed\n");
	}
	return 0;
}