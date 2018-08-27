#include <stdio.h>

int main() {
	int A, B, D, sum;
	scanf("%d %d %d", &A, &B, &D);
	sum = A + B;// 和 <= 2^31,因此即使1进制，总共的位数 <= 10^10
	int num[100] = {0}, index = 0;//记录位数上对应的数
 	do {
		num[index++] = sum % D;
		sum /= D;
	} while (sum != 0);
	for (int i = index - 1; i >= 0; i--){
		printf("%d", num[i]);
	}
	return 0;
}