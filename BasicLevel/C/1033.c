/* 
 * 不能输出的类型：
 *	1. 坏键；
 *	2. 上档键坏了，大写字母； 
 * 注意：将遍历条件 字符串长度 提前计算。避免每次遍历时计算字符串长度导致超时
 */
#include <stdio.h>
#include <string.h>
#include <ctype.h>

int main() {
	char str1[42], str2[100001];//坏掉的键最多41个 
	gets(str1);//读入输入 
	gets(str2);
	int key[128] = {0}, len1 = str1.length();
	for(int i = 0; i < len1; i++) //标记失效键 
		key[str1[i]] = 1;
	int len2 = strlen(str2);//避免 每次遍历都要计算导致超时 
	for(int i = 0; i < len2; i++) {
		if(key[toupper(str2[i])]) { //坏键 
			continue;
		} else if(key['+'] && isupper(str2[i])) { //上档键坏 且 为大写字母 
			continue; 
		}
		printf("%c", str2[i]);
	} 
	printf("\n"); 
	return 0;
}