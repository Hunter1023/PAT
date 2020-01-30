/*
 * 1. C语言有三角函数库，位于 <math.h>
 * 2. C语言的格式化输出保留小数，默认四舍五入，在接近0的负数四舍五入之后不输出0.00，而是-0.00。
 */
#include <stdio.h>
#include <math.h>

int main(){
	double R1, P1, R2, P2;
	scanf("%lf %lf %lf %lf", &R1, &P1, &R2, &P2);
	double R = R1 * R2, P = P1 + P2;//由指数形式易得 两数乘积的R和P
	double A = R * cos(P), B = R * sin(P);
	if (A < 0 && A > -0.005) {
		A = 0.00;
	} 
	if (B < 0 && B > -0.005) {
		B = 0.00;
	} 
	printf("%.2f%+.2fi\n", A, B);// %+：有符号，值若>=0，在值前显示加号；若为负，则在值前显示负号
	return 0;
}