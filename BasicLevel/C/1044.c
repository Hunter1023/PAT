/*
 * （读取字符要注意回车的处理 可回顾一下 1018. 锤子剪刀布）
 * 1. 创建二维字符数组的 长度
 * 2. 含高位的火星文，如果低位是0，不输出
 */
#include <stdio.h>
#include <string.h>
#include <ctype.h>

int main() {
	char digit[13][5] = {"tret", "jan", "feb", "mar", "apr", "may", "jun", "jly", "aug", "sep", "oct", "nov", "dec"};
	char high[13][4] = {"#", "tam", "hel", "maa", "huh", "tou", "kes", "hei", "elo", "syy", "lok", "mer", "jou"};
	int N;
	scanf("%d\n", &N);//注意回车的读取
	char num[8];//输入的内容 最长长度为7（包括空格） 
	for (int i = 0; i < N; i++) {//读入地球文或火星文 
		gets(num); 
		if (isdigit(num[0])) {//如果是地球数字 
			int d = strlen(num), n = 0;//位数，数字
			for (int j = 0; j < d; j++) {
				n = 10*n + num[j] - '0';
			}
			if (n > 12) {//两位火星文 
				printf("%s", high[n/13]);
				if (n % 13 != 0) {//低位不是0
					printf(" %s", digit[n%13]);
				}
			} else {//一位火星文 
				printf("%s", digit[n]);
			}
		} else {//输入的是火星文 
			int result = 0;
			for (int j= 0; j < 13; j++) {
				if (strstr(num, digit[j])) {//存在对应的字符串 
					result += j;
					break;
				}
			}
			for (int j = 1; j < 13; j++) {
				if (strstr(num, high[j])) {
					result += j*13;
					break;
				}
			}
			printf("%d", result);
		}
		printf("\n");
	}
	return 0;
}