#include <stdio.h>
#include <string.h>
#include <ctype.h>

int main() {
	char str[1001];
	int cnt[26] = {0};
	gets(str); //读入字符串
	int len = strlen(str);
	for(int i = 0; i < len; i++) { //遍历字符串 
		if(isalpha(str[i])) //如果是英文字母 
			cnt[tolower(str[i])-'a']++;
	} 
	int max = 0;
	for(int i = 1; i < 26; i++) {
		if(cnt[i] > cnt[max]) {
			max = i;
		}
	}
	printf("%c %d\n", 'a' + max, cnt[max]);
	return 0;
}