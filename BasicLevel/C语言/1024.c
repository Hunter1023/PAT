#include <stdio.h>
#include <string.h>

int main() {
	char A[10000] = "0";
	scanf("%s", A);
	int index_E = 0, expo = 0;//E的下标, 指数 
	for (int i = 0; i < strlen(A); i++) {
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
		printf("0.");
		for (int i = 1; i < expo; i++) {//再输出指数-1个0 
			printf("0");
		} 
		for (int i = 1; i < index_E; i++) {
			if (i != 2) {//忽略小数点 
				printf("%c", A[i]);
			}
		}
	} else {//指数为正 
		if (expo >= index_E - 2 - 1) {//如果指数>=小数位数，不保留小数点 
			for (int i = 1; i < index_E; i++) {
				if (i != 2) {//忽略小数点 
					printf("%c", A[i]);
				}
			}
			while ( expo - (index_E - 2 - 1) > 0) {
				printf("0");
				expo--;
			}
		} else {//指数 < 小数位数，保留小数点 
			for (int i = 1; i < index_E; i++) {
				if (i != 2) {//忽略小数点 
					printf("%c", A[i]);
					if ( i == 2 + expo) {
						printf(".");
					}
				} 
			}
		}
	}
	return 0;
}