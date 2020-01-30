/*
 * 1. 分子和分母全是整型范围内的整数：long
 * 2. 有理数的输出：
 *  2.1 负数的判断 需要同时考虑分子和分母（除法运算导致分母可能为负数）；
 *  2.2 化简分数 —— 辗转相除法，求最大公约数
 *	2.3 三种形式:
 *		- 有整数和分数
 *		- 只有整数
 *		- 只有分数
 */
#include <stdio.h>

long getgcd(long a, long b) {//最大公约数， 辗转相除法 
	return b == 0 ? a : getgcd(b, a % b);//令 a = b; b = a % b 
}
void printfrac(long n, long d) { //打印分数 
    if(d == 0) { //分母为0 
		printf("Inf"); 
		return; 
	}
    int isNegative = 0; //是否为负数 
    if(n < 0) { //分子为负 
		n = -n; 
		isNegative = !isNegative; 
	}
    if(d < 0) { //分母为负 
		d = -d;
		isNegative = !isNegative;
	}
    long gcd = getgcd(n, d);  //获取最大公约数         
    n /= gcd;//化简 
    d /= gcd;
    if(isNegative) {//负数 输出 (- 
		printf("(-");
	} 
    if(n / d && n % d) {//有整数部分和分数部分 
		printf("%ld %ld/%ld", n / d, n % d, d);
	} else if (n % d) {//只有分数 
	    printf("%ld/%ld", n % d, d);
	} else { //只有整数 
        printf("%ld", n / d); 
    } 
    if(isNegative) { //如果是负数 
		printf(")");
    } 
}
int main() {
    long a1, b1, a2, b2;
    scanf("%ld/%ld %ld/%ld", &a1, &b1, &a2, &b2);
    char op[4] = {'+', '-', '*', '/'};
    for(int i = 0; i < 4; i++) {
        printfrac(a1, b1);
		printf(" %c ", op[i]);
        printfrac(a2, b2);
		printf(" = ");
        switch(op[i]) {
            case '+': 
				printfrac(a1 * b2 + a2 * b1, b1 * b2); 
				break;
            case '-': 
				printfrac(a1 * b2 - a2 * b1, b1 * b2); 
				break;
            case '*': 
				printfrac(a1 * a2, b1 * b2); 
				break;
            case '/': 
				printfrac(a1 * b2, b1 * a2); 
				break;
        }
        printf("\n");
    }
    return 0;
}