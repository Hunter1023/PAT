#include <stdio.h>
#include <ctype.h>

int main() {
	int weight[17] = {7, 9, 10, 5, 8, 4, 2, 1,
					6, 3, 7, 9, 10, 5, 8, 4, 2};
	char check[12] = "10X98765432"; 
	int N, allRight = 1;
	scanf("%d", &N);
	while(N--) {
		char id[19];
		scanf("%s", id);
		int sum = 0, isTrue = 1; //权重和，当前身份证号码是否正常
		for(int i = 0; i < 17; i++) {
			if(!isdigit(id[i])) { //不是数字
				isTrue = 0;
				break; 
			}
			sum += (id[i] - '0') * weight[i];
		} 
		if (isTrue && check[sum % 11] != id[17]) //都是数字 且 校验码无效 
			isTrue = 0;
		if (!isTrue) { //如果身份证有问题，输出 
			allRight = 0;
			printf("%s\n", id);	
		}
	}
	if (allRight)
		printf("All passed\n");
	return 0;
}