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
	int hasShift = 1;//有上档键 
	if (strchr(str1, '+')) {//如果上档键坏了，标注 
		hasShift = 0;
	}
	int len = strlen(str2);//避免 每次遍历都要计算导致超时 
	for (int i = 0; i < len; i++) {
		if (strchr(str1, toupper(str2[i]))) {//如果直接是坏键，肯定不能打印 
			continue;
		} else if (!hasShift && isupper(str2[i])) {//上档键坏了,是大写字母 
			continue; 
		} 
		printf("%c", str2[i]);
	} 
	printf("\n"); 
	return 0;
}