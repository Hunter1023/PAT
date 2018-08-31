#include <stdio.h>
#include <string.h>

int main() {
	char A[10000];
	scanf("%s", A);
	int index_E = 0, expo = 0;//E的下标, 指数 
	for (int i = 0; i < strlen(A); i++) {//获取E的下标 
		if (A[i] == 'E') {
			index_E = i;
			break;
		}
	}
	for (int i = index_E + 2; i < strlen(A); i++) {//求得指数的绝对值 
		expo = 10*expo + (A[i] - '0');
	} 
	if (A[0] == '-') {//如果实数为负数，输出负号 
		printf("-");
	} 
	if (A[index_E+1] == '-') {//指数为负 
		for (int i = 0; i < expo; i++) {//输出 指数个0 
			printf("0");
			if (i == 0) {
				printf(".");
			}
		} 
		for (int i = 1; i < index_E; i++) {//输出科学计数法数字部分的数字 
			if (i != 2) {//忽略小数点 
				printf("%c", A[i]);
			}
		}
	} else {//指数为正 
		for (int i = 1; i < index_E; i++) {//输出科学计数法数字部分的数字
			if (i != 2) {//忽略小数点 
				printf("%c", A[i]);
				if (i == 2 + expo && i != index_E - 1) {//如果指数 = 小数位数，不保留小数点
					printf(".");
				}
			}
		}
		for (int i = 0; i < expo - (index_E - 3); i++) {//若指数还有多余部分，转为0 
			printf("0");
		}
	}
	return 0;
}