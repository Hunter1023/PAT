/*
 * 1. 分子和分母全是整型范围内的整数：long int
 * 2. 有理数必须是最简形式
 *	2.1 假分式转换为真分式 
 *	2.2 化简到分子分母的最大公约数为1
 * 3. 负数的分号需要放在分子前，先判断正负，再取分子分母绝对值进行计算
 *	3.1 负数的判断需要同时考虑分子和分母，（除法运算会导致分母可能为负数）
 */
#include <stdio.h>

long int getgcd(long int a, long int b) {//最大公约数， 辗转相除法 
	return b == 0 ? a : getgcd(b, a % b);//令 a = b; b = a % b 
}
void handle(long int a, long int b) {//对有理数的基本处理 
	if (b == 0) {//分母为0 
		printf("Inf");
	} else if (a == 0) {//分子是0，输出0 
		printf("0");
	} else {
		int isneg = ((a < 0 && b > 0) || (a > 0 && b < 0)) ? 1:0;//是否为负数，除法运算会导致分母可能为负数 
		if (isneg) {//如果是负数 
			printf("(-");//加括号
		}
		if (b < 0) {
			b = -b;
		}  
		if (a < 0) {
			a = -a;
		}
		if ( a / b != 0) {//假分数
			printf("%ld", a / b);
			if ((a = a % b) == 0) {//如果是整数 
				if (isneg) {//如果是负数 
					printf(")");//加括号
				} 
				return;
			} else {
				printf(" ");
			}
		}
		if (a != 0) {//如果是真分数 
			long int gcd = getgcd(a, b);//最大公约数 
			printf("%ld/%ld", a / gcd, b / gcd);
		} 
		if (isneg) {//如果是负数 
			printf(")");//加括号
		} 
	}
}
void add(long int a1, long int b1, long int a2, long int b2) {//加法的结果
	handle(a1, b1);
	printf(" + ");
	handle(a2, b2);
	printf(" = ");
	long int a = a1 * b2 + a2 * b1;
	long int b = b1 * b2;
	handle(a, b); 
	printf("\n"); 
}
void sub(long int a1, long int b1, long int a2, long int b2) {//减法的结果 
	handle(a1, b1);
	printf(" - ");
	handle(a2, b2);
	printf(" = ");
	long int a = a1 * b2 - a2 * b1;
	long int b = b1 * b2;
	handle(a, b); 
	printf("\n");
}
void multi(long int a1, long int b1, long int a2, long int b2) {//乘法 
	handle(a1, b1);
	printf(" * ");
	handle(a2, b2);
	printf(" = ");
	long int a = a1 * a2;
	long int b = b1 * b2;
	handle(a, b); 
	printf("\n");
}
void div(long int a1, long int b1, long int a2, long int b2) {
	handle(a1, b1);
	printf(" / ");
	handle(a2, b2);
	printf(" = ");
	long int a = a1 * b2;
	long int b = b1 * a2;//分母可能为负数 
	handle(a, b);
	printf("\n");
}
int main() {
	long int a1, b1, a2, b2;
	scanf("%ld/%ld %ld/%ld", &a1, &b1, &a2, &b2);
	add(a1, b1, a2, b2);
	sub(a1, b1, a2, b2);
	multi(a1, b1, a2, b2);
	div(a1, b1, a2, b2);
	return 0;
} 