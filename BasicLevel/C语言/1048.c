/*
 * 当加密的正整数A比B长时，需要默认B的不足位数为0，继续进行计算（题目输入样例不足导致的理解坑）
 * 待优化
 */
#include <stdio.h>
#include <string.h>

int main() {
    char A[101], B[101], result[101] = {0};//加密整数A 和 B，结果 
	scanf("%s %s", A, B);
	char num[13] = "0123456789JQK";
	int isodd = 1;//是否奇数位 
	int result_len = strlen(A) >= strlen(B) ? strlen(A) : strlen(B); 
	for(int i = strlen(B) - 1, j = strlen(A) - 1; i >= 0 && j >= 0; i--, j--) {//A、B对应位都存在时 
		if (isodd) {//奇数位 
			result[--result_len] = num[(A[j] + B[i] - 2 * '0') % 13];
			isodd = 0;
		} else {//偶数位
			result[--result_len] =  (B[i] - A[j]) < 0 ? num[B[i] - A[j] + 10] : num[B[i] - A[j]];
			isodd = 1;
		}
	}
	int Alonger = strlen(A) - strlen(B);
	if (Alonger < 0) {//如果整数比加密的整数长 
		for (int i = 0; i < strlen(B) - strlen(A); i++) {
			result[i] = B[i];
		}
	} else {
		while (Alonger-- > 0) {
			if (isodd) {
				result[Alonger] = A[Alonger];
				isodd = 0;
			} else {
				if (A[Alonger] == '0') {
					result[Alonger] = '0';
				} else {
					result[Alonger] = 10 + ('0' - A[Alonger]) + '0';
				}
				isodd = 1;
			}
		} 
	}
	printf("%s\n", result);
    return 0;
}