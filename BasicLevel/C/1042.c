/* 只统计英文字母，不区分大小写 */
#include <stdio.h>
#include <string.h>
#include <ctype.h>

int main() {
	char str[1001];//初始字符串 
	int arr[26] = {0};//最多26个英文字母（不区分大小写） 
	gets(str);//读入字符串
	for (int i = 0; i < strlen(str); i++) {//遍历字符串 
		if (isalpha(str[i])) {//如果是英文字母 
			str[i] = tolower(str[i]);
			arr[str[i]-'a']++;
		} 
	} 
	int maxcnt = 0;//出现频率最高的那个英文字母及其出现次数
	char c;
	for (int i = 0; i < 26; i++) {
		if (arr[i] > maxcnt) {
			c = 'a' + i;
			maxcnt = arr[i];
		}
	}
	printf("%c %d\n", c, maxcnt);
	return 0;
}