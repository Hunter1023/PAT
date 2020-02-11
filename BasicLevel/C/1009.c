/* 句子颠倒，单词本身字母不颠倒
 * 方法一：scanf()读取字符串
 */
#include <stdio.h>

int main() {
	char word[80][81];
	int cnt = 0;
	while(scanf("%s", word[cnt]) != EOF) //统计单词数量
		cnt++; 
	for(int i = cnt - 1; i >= 0; i--) {
		printf("%s", word[i]);
		if(i != 0)
			printf(" ");
	}
	return 0;
}

/** 方法二：gets()读取字符串
#include <stdio.h>
#include <string.h> 

int main() {
	char str[81]; //创建字符串
	gets(str); //读取字符串
	for(int i = strlen(str) - 1; i > 0; i--) { //从末尾开始遍历字符串 
		if(str[i] == ' ') {  
			printf("%s ", str + i + 1);  
			str[i] = '\0'; //把空格改为 \0，使后续输出也只有一个单词
		}	
	} 
	printf("%s", str); //输出第一个单词 
	return 0; 
}
*/