/*
 * 1. 需要让A和B 对应的位进行计算
 * 2. 正整数整数A和B如果长度不一，高位补0使长度一致，进行计算
 * 3. 输出从最高位开始输出
 */
#include <stdio.h>
#include <string.h>

int main() {
    char A[101], B[101];
    scanf("%s %s", A, B);
    char num[14] = "0123456789JQK";
    int lenA = strlen(A), lenB = strlen(B);
    int maxlen = lenA > lenB ? lenA : lenB;
    int a, b;
    for(int i = 0; i < maxlen; i++) {
        a = lenA + i - maxlen < 0 ? 0 : A[lenA + i - maxlen] - '0';//对应位不存在时，为0 
        b = lenB + i - maxlen < 0 ? 0 : B[lenB + i - maxlen] - '0';
        if((maxlen - i) % 2 == 1) { //奇数位 
        	 printf("%c", num[(a + b) % 13]);
		} else {//偶数位 
			printf("%d", (b - a < 0 ? b - a + 10 : b - a));
		}
	}
    return 0;
}