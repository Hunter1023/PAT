/*
 * 1. 对齐两个整数 
 * 		若加密正整数A 比 B 长，B高位不足的部分补0后进行加密 
 * 		若加密正整数A 比 B 短，B多余的部分正常输出，效果等同于A补0后进行加密 
 * 2. 结果从数字高位(字符串低位)开始输出
 */ 
#include <cstdio>
#include <cstring>

int main() {
	char A[101], B[101];
    scanf("%s %s", A, B);
    char num[14] = "0123456789JQK";
    int lenA = strlen(A), lenB = strlen(B);
    int maxlen = lenA > lenB ? lenA : lenB;
    for(int i = 0; i < maxlen; i++) {
        int a = i + lenA - maxlen < 0 ? 0 : A[i + lenA - maxlen] - '0';//对应位不存在时，为0 
        int b = i + lenB - maxlen < 0 ? 0 : B[i + lenB - maxlen] - '0';
        if((maxlen - i) % 2 == 1) { //奇数位 
        	 printf("%c", num[(a + b) % 13]);
		} else { //偶数位 
			printf("%d", (b - a < 0 ? b - a + 10 : b - a));
		}
	}
	return 0;
}