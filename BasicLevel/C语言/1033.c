/* 将 需要计算的判断条件，从遍历中提取出来，避免重复计算导致超时 */
#include <stdio.h>
#include <stdbool.h>
#include <string.h>
#include <ctype.h>

int main() {
	char str1[42], str2[100001];//坏掉的键最多41个 
	gets(str1);//可能没有坏键，保证读入正确 
	gets(str2);
	bool hasShift = true;
	if (strchr(str1, '+')) {//如果上档键坏了，标注 
		hasShift = false;
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