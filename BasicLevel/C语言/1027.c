/**
 * 平方根的函数 double sqrt(double x); 
 */
#include <stdio.h>
#include <math.h>

int main() {
	int N;
	char sign;
	scanf("%d %c", &N, &sign);
	int h = (int)sqrt((N+1) / 2.0); //半个沙漏的高度 
	int max = 2 * h - 1;
	int cnt_space = 0;//空格数量 
	for (int i = max; i > 0; i -= 2) {
		for (int j = 0; j < cnt_space; j++) {
			printf(" ");
		}
		cnt_space++;
		for (int j = i; j > 0; j--) {
			printf("%c", sign);
		}
		printf("\n");
	}
	cnt_space -= 2;
	for (int i = 3; i <= max; i += 2) {
		for (int j = 0; j < cnt_space; j++) {
			printf(" ");
		}
		cnt_space--;
		for (int j = i; j > 0; j--) {
			printf("%c", sign);
		}
		printf("\n");
	}
	printf("%d",N + 1 - 2*h*h);
	return 0;
}