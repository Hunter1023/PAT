#include <stdio.h>
#include <string.h> 

int main() {
	char str[81];//创建字符串，和指针 
	gets(str);//读取字符串
	int i = 0;//数组下标 
	for (i = strlen(str); i > 0; i--) {//从末尾开始遍历字符串 
		if (str[i] == ' ') {//如果遇到空格 
			printf("%s ", &str[i+1]);//输出空格后的单词 
			str[i] = '\0'; //把空格改为 \0 
		}	
	} 
	printf("%s", &str[i]); //输出原字符串的第一个单词 
	return 0; 
}