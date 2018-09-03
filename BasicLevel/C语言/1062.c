/*
 * 输入的两个正分数，没有表明哪个大哪个小，需要判断
 * 辗转相除法获取最大公约数
 */
#include <stdio.h>

int gcd(int a, int b) {//最大公约数 
	while (b != 0) {
		int temp = a % b;
		a = b;
		b = temp;
	}
	return a;
}
int main(){
	int N1, M1, N2, M2, K;
	scanf("%d/%d %d/%d %d", &N1, &M1, &N2, &M2, &K);
	if (N1 * M2 > N2 * M1) {
		int tempN = N1, tempM = M1;
		N1 = N2;
		N2 = tempN;
		M1 = M2;
		M2 = tempM;
	}
	int isfirst = 1;
	for (int i = 1; i < K; i++) {
		if (gcd(i, K) == 1 && (i * M1 > N1 * K)) {
			if (i * M2 < N2 * K) {
				if (!isfirst) {
					printf(" ");
				}
				printf("%d/%d", i, K);
				isfirst = 0;
			} 
		} 
	}
	printf("\n");
	return 0;
}