/*
 * 1. 末尾临界字符的处理
 * 2. 连续相同的字符的个数可能是十位数、百位数甚至千位数
 */
#include <stdio.h>
#include <ctype.h>
#include <string.h>

int main() {
	char c, str[1001], result[1001];
	scanf("%c", &c);
	getchar();
	gets(str);
	int len = strlen(str);
	if (c == 'C') {//压缩 
		int i;
		for (i = 0; i < len; i++) {
			int cnt = 1;
			while (str[i] == str[i + 1] && i < i < len-1) {//相邻的字符相同 
				cnt++;//统计字符数量 
				i++;
			}
			if (cnt > 1) {
				printf("%d", cnt);
			} 
			printf("%c", str[i]);
		}
		if (i == len - 1) {
			printf("%c", str[i]);
		}
	} else {//解压 
		for (int i = 0; i < len; i++) {
			int cnt = 1;
			if (isdigit(str[i])) {//是数数字 
				cnt = str[i]- '0';
				while (isdigit(str[++i])) {//后续还有数字 
					cnt = 10*cnt + str[i]- '0';
				}
			}
			while (cnt > 0) {
				printf("%c", str[i]);
				cnt--;
			}
		}
	} 
	printf("\n");
	return 0;
}