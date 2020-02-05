#include <stdio.h>
#include <math.h>

int main() {
	int N;//正方形边长
	char C; //字符 
	scanf("%d %c", &N, &C);
	int row = (int)round(N / 2.0); //行数 
	for (int i = 0; i < row; i++) {
		for (int j = 0; j < N; j++) { //第一行，最后一行
			if (i == 0 || i == row - 1 || j == 0 || j == N - 1) {//每行的头尾
				printf("%c", C); 
			} else {
				printf(" ");
			}
		}
		printf("\n");
	}
	return 0;
}