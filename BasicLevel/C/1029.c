/*
 * 1. 字母坏键只输出大写；故最差情况按键全坏为，37个字符
 * 2. 利用 char *strchr(const char *s,char c);//不存在则返回NULL  判断是否坏键
 */
#include <stdio.h>
#include <string.h>
#include <ctype.h>

int main() {
	char str1[81], str2[81], result[38] = {'\0'};
	scanf("%s\n%s", str1, str2);
	int index = 0; //result的下标
	for(int i = 0; i < strlen(str1); i++) {//遍历第一行字符串 
		if(!strchr(str2, str1[i]) && !strchr(result, toupper(str1[i]))) {//输出字符串中没有该字符 且 字符未记录
			result[index] = toupper(str1[i]); //记录坏键
			index++;
		}
	}
	result[index] = '\0';
	printf("%s\n", result);
	return 0;
}