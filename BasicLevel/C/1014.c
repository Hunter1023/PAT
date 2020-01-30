/**
 * 1. 解码的方式：
 * 		1.1 星期：第1对相同的 大写英文字母
 * 		1.2 小时：第2对相同的 数字 或 A - N 之间的大写英文字母
 * 		1.3 分钟：第1对相同的 英文字母（无论大小写）
 * 2. 小时和分钟都显示为两位数
 */
#include <stdio.h>
#include <string.h>
#include <ctype.h>

int main() {
	char str[4][61];
	char day[][4] = {"MON", "TUE", "WED", "THU", "FRI", "SAT", "SUN"};
	int cnt = 0;//记录是第几对相同的字符 
	for (int i = 0; i < 4; i++) {
		gets(str[i]);
	} 
	for (int i = 0; i < strlen(str[0]) && i < strlen(str[1]); i++) { //遍历1、2两行字符串 
		if (cnt == 0 && str[0][i] == str[1][i] && 
			str[0][i] >= 'A' && str[0][i] <= 'G') {//第一对相同的 大写英文字母
			printf("%s ", day[str[0][i] - 'A']);//输出星期
			cnt++; 
		} else if (cnt == 1 && str[0][i] == str[1][i] && 
					(isdigit(str[0][i]) || str[0][i] >= 'A' && str[0][i] <= 'N')) {//第二对相同的 数字 或 一定范围内的 大写英文字母
			if (str[0][i] >= '0' && str[0][i] <= '9') {
				printf("%02d:", str[0][i] - '0');//输出小时 
			}else {
				printf("%d:", str[0][i] - 'A' + 10);//输出小时
			}
			break;
		}
	}
	for (int i = 0;  i < strlen(str[2]) && i < strlen(str[3]); i++ ) {
		if (str[2][i] == str[3][i] && isalpha(str[2][i])) {// 第1对相同的 英文字母
			printf("%02d\n", i);
			break;
		}
	}
	return 0; 
}