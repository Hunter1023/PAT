#include <stdio.h>
#include <math.h>

int main() {
	int N;//正方形边长
	char C;
	scanf("%d %c", &N, &C);
	int row = (int)round(N / 2.0) - 2;//除首尾两行的行数 
	for (int i = 0; i < N; i++) {
		printf("%c", C);
	}
	printf("\n");
	while (row-- > 0) {
		printf("%c", C);
		for (int i = 0; i < N - 2; i++) {
			printf(" ");
		}
		printf("%c", C);
		printf("\n");
	}
	for (int i = 0; i < N; i++) {
		printf("%c", C);
	}
	printf("\n");
	return 0;
}