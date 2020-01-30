/*
 * 1. 合法的输入最长为8（-1000.00）;
 * 2. 严谨解法：
 *		2.1 scanf("%8s", str); 读取 最多前8个字符
 *  	2.2 利用 ungetc(getchar(), stdin); 读取之后的字符，并推回（避免不必要的误读）；
 *		2.3 isspace(c); 判断是否读取了空白字符 来判断读入是否完整； 
 * 3. 非法的情况
 * 		3.1 输入长度 > 8；
 *		3.2 输入数字大小 > 1000 或 < -1000；
 *		3.3 不是数字 或 小数点的位数不对
 *  		- 利用 sscanf( string str, string fmt, mixed var1, mixed var2 ... );
 *  和 sprintf(char *str, char * format [, argument, ...]); , 与原输入进行比较。
 * 4. 输出：
 *		- 只有当合法输入的个数为1时，输出内容 The average of 1 number is Y 中， 
 *    number才为单数，个数为0依然是numbers。
 */
#include <stdio.h>
#include <string.h>
#include <stdlib.h>
#include <ctype.h> 

int main() {
	int N, K = 0;	//输入的数量，合法输入的个数
	double sum = 0.0, temp = 0.0;	// 合法输入实数的和，临时存储的实数 
	char num[9], str[9], c;	// 合法输入最长为 8；c用于读取多余字符 
	scanf("%d", &N);
	for (int i = 0; i < N; i++) {
		scanf("%8s", str);	//读取 最多前8个字符
		c = ungetc(getchar(), stdin); //读取下一个字符 并 将其推回
		int len = strlen(str), isLegal = 0;	//读取的字符串长度 判断是否合法 
		if (isspace(c)) { //之后是空白字符（空格、回车），即字符读取完全
			isLegal = 1;
			sscanf(str, "%lf", &temp);		//将字符串转为浮点数类型 
			sprintf(num, "%.2f", temp);	//将浮点数精确到小数点后两位 转为字符串;
			for (int j = 0; j < len; j++) {
				if (num[j] != str[j]) {	//如果处理前后的字符串不一致，就是非法输入 
					isLegal = 0;
					break;
				}
			}
		} 
		if (!isLegal || temp > 1000 || temp < -1000) {//如果是非法输入
			printf("ERROR: %s", str);
			while (!isspace(c = getchar())) {//将字符串完全输出 
				putchar(c); 
			}
			printf(" is not a legal number\n");
		} else {
			sum += temp;
			K++;
		}
	}
	if (K == 0) { //平均值无法计算 即 分母为0 
		printf("The average of 0 numbers is Undefined\n");
	} else if (K == 1) { 
		printf("The average of 1 number is %.2f\n", sum);
	} else { 
		printf("The average of %d numbers is %.2f\n", K, sum / K);
	} 
	return 0;
}