/*  0 < A, B < 10^{​10}，故用int long创建数字 */
#include <stdio.h>

int main() {
	long int num[2], P[2] = {0};
	int D[2];
	scanf("%ld %d %ld %d", &num[0], &D[0], &num[1], &D[1]);
	for (int i = 0; i < 2; i++) {
		while (num[i] > 0) { //当数字不为0时 
			if (num[i] % 10 == D[i]) { //如果有位数是D 
				P[i] =  P[i] * 10 + D[i]; //更新整数P
			}
			num[i] /= 10; 
		}
	}
	printf("%ld\n", P[0] + P[1]); 
	return 0; 
}