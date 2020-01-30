#include <stdio.h> 
#include <stdlib.h>

void Prt(int M, double i) {
	if (M < i) {
		printf(" Cong");
	} else if (M == i) {
		printf(" Ping");
	} else {
		printf(" Gai");
	}
}

int main() {
	int M, X, Y, A, B; //设甲、乙能力值为A、B
	double C; //设丙的能力值为C
	scanf("%d %d %d", &M, &X, &Y);
	for (A = 99; A >= 10; A--) {//甲的能力值为2位整数，遍历寻找符合的最大解 
		B = A % 10 * 10 + A / 10;
		if (abs(A-B) * 1.0 / X == B * 1.0 / Y) {// 找到符合条件的能力值 
			C = B * 1.0 / Y;
			printf("%d", A);
			Prt(M, A);
			Prt(M, B);
			Prt(M, C);
			return 0;
		}
	}
	printf("No Solution"); 
	return 0;
}
