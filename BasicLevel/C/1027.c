/**
 * 沙漏图形的特征：
 * 	1. 上下对称；上半个沙漏符号数量 (1+3+5+...) 
 *		可得出总符号数 N 和半个沙漏高度 H 的关系 ==> 2 * H * H - 1 <= N
 * 	2. 上半部分： 每行空格数量递增 +1；符号数量递减 -2
 * 每行的输出 
 *	根据对称性，可以用绝对值函数 abs()，减少代码量；
 */
#include <stdio.h>
#include <math.h>

int main() {
    int N, h;//符号的数量 ，半个沙漏的高度 
    char sign; //符号 
    scanf("%d %c", &N, &sign);
    h = (int)sqrt((N+1) / 2.0);
    for (int i = 0; i < 2 * h - 1; i ++) {//输出每行内容 
        for (int j = 0; j < h - 1 - abs(h - 1 - i); j++) {
			printf(" ");
		} 
        for (int j = 0; j < 2 * abs(h - 1 - i) + 1; j++) {
			printf("%c", sign);
		} 
        putchar('\n');
    }
    printf("%d", N - 2 * h * h + 1);
    return 0;
}