/*实际测试数据的范围应该是 [-2^63, 2^63 - 1] */
#include <cstdio>

int main() {
	int T;
	scanf("%d", &T);
	for (int i = 1; i <= T; i++) {
		long long A, B, C, sum;
		scanf("%lld %lld %lld", &A, &B, &C);
		sum = A + B; //A、B同号时，可能溢出；正溢出得负数，负溢出得 非负数
		printf("Case #%d: ", i);
		if (A > 0 && B > 0 && sum < 0) { //正溢出  
			printf("true\n");
		} else if (A < 0 && B < 0 && sum >= 0) { //负溢出 
			printf("false\n");
		} else if (sum > C) {
			printf("true\n");
		} else {
			printf("false\n");
		}
	} 
	return 0;
}
