/*
 * 1. 输入含空格的字符串：用 gets() 读取
 * 2. 句子颠倒，单词本身字母不颠倒：
 *		2.1 从末尾单词开始输出
 * 		2.2 利用指针使单词本身正序
 *		2.3 空格是单词结束的标识
 */
#include <stdio.h>
#include <string.h> 

int main() {
	char str[81]; //创建字符串
	gets(str); //读取字符串
	int i = 0; //数组下标 
	for (i = strlen(str); i > 0; i--) { //从末尾开始遍历字符串 
		if (str[i] == ' ') { //如果遇到空格 
			printf("%s ", &str[i+1]); //输出空格后的单词 
			str[i] = '\0'; //把空格改为 \0，使后续输出也只有一个单词
		}	
	} 
	printf("%s", &str[i]); //输出原字符串的第一个单词 
	return 0; 
}