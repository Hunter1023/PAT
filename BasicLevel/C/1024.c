/**
 * 1. 读取科学计数 —— 利用正则表达式，分开读取 数字部分 和 指数部分
 * 2. 判断正负，负数输出 负号
 * 3. 判断指数正负：
 *		3.1 指数 < 0：整数部分必然为 0
 *		3.2 指数 >= 0：
 *			- 仍有小数点，何时输出小数点（重点）
 *			- 没有小数点，后续输出0
 */
#include <stdio.h>
#include <string.h>

int main() {
	char A[10000];
	int expo;
	scanf("%[^E]E%d", A, &expo);
	if (A[0] == '-') {//如果实数为负数，输出负号 
		printf("-");
	} 
	if (expo < 0) {//指数为负
		printf("0."); 
		for (int i = 1; i < -expo; i++) {//输出 指数个0 
			printf("0");
		} 
		for (int i = 1; i < strlen(A); i++) {//输出科学计数法数字部分的数字 
			if (i != 2) {//忽略小数点 
				printf("%c", A[i]);
			}
		}
	} else {//指数 >= 0
		for (int i = 1; i < strlen(A); i++) {//输出科学计数法数字部分的数字
			if (i != 2) {//忽略小数点 
				printf("%c", A[i]);
			}
			if (i - 2 == expo && i != strlen(A) - 1) {//如果小数当前位数==指数 且 不是最后一位小数 ，输出小数点
				printf(".");
			}
		}
		while (expo-- > strlen(A) - 3 ) {//若指数 > 小数部分，输出0 
			printf("0");
		}
	}
	return 0;
}