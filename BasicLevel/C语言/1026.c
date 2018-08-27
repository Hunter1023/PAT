/*四舍五入的函数是 double round(double x); */
#include <stdio.h>
#include <math.h>

int main() {
	const int CLK_TCK = 100;
	double C1, C2;
	scanf("%lf %lf", &C1, &C2);
	int time = (int)round((C2 - C1) / CLK_TCK);
	int hour = time / 60 / 60;
	int minute = time / 60 % 60;
	int second = time % 60;
	printf("%02d:%02d:%02d\n", hour, minute, second);
	return 0;
}