/* 密码为非空字符串，可能含有空格，不能用scanf读取 */ 
#include <stdio.h>
#include <string.h>
#include <ctype.h>

int main() {
	int N;
	scanf("%d\n", &N);
	char password[81];
	for (int i = 0; i < N; i++) {
		int hasNum = 0, hasAlpha = 0, isLegal = 1;
		gets(password);
		int len = strlen(password);
		if (len < 6) {//密码太短 
			printf("Your password is tai duan le.\n");
		} else {
			for (int j = 0; j < len; j++) {
				if (!isalpha(password[j]) && !isdigit(password[j])
					 && password[j] != '.') {//有非法字符 
					printf("Your password is tai luan le.\n");
					isLegal = 0;
					break;
				} else if (isalpha(password[j])) {
					hasAlpha = 1; 
				} else if (isdigit(password[j])) {
					hasNum = 1;
				}
			}
			if (isLegal) {
				if (hasAlpha && hasNum) {//密码合法 
					printf("Your password is wan mei.\n");
				} else if (!hasNum && hasAlpha) {//没有数字 
					printf("Your password needs shu zi.\n");
				} else if (!hasAlpha && hasNum) {//没有字母 
					printf("Your password needs zi mu.\n");
				} 
			}
		} 
	}
	return 0;
}