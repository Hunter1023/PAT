#include <stdio.h>
#include <string.h>

int main() {
	char A[1001];//被除数
	int B, Q, R = 0;//除数、商、余数 
	scanf("%s %d", &A, &B);
	//将问题转换为 十位数 / 个位数
	for(int i = 0; i < strlen(A); i++) {
		Q = (10 * R + (A[i] - '0')) / B;
		if (!(i == 0 && Q == 0 && strlen(A) != 1)) { //如果首位被除 商是0，被除数不是个位数，则不输出0
			printf("%d", Q);
		}
		if ((10 * R + (A[i] - '0')) % B != 0) {//更新余数
			R = (10 * R + (A[i] - '0')) % B;
		} else {
			R = 0;
		}
	}
	printf(" %d\n", R);
	return 0; 
}