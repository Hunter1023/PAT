/**
 * 沙漏图形的特征：
 * 	1. 上下对称；设半个沙漏高度为H，上半个沙漏符号数量 (1+3+5+...+2*H-1) 
 *		可得出总符号数 N 和半个沙漏高度 H 的关系 ==> 2 * H * H - 1 <= N
 * 	2. 上半部分： 每行空格数量递增 +1；符号数量递减 -2
 *	3. 下半部分： 每行空格数量递减 -1；符号数量递增 +2
 */
#include <cstdio>
#include <cmath>

int main() {
    int N, H; //符号的数量 ，半个沙漏的高度 
    char C; //符号 
    scanf("%d %c", &N, &C);
    H = sqrt((N + 1) / 2.0);
    for(int i = H; i > 0; i--) { //输出上半个沙漏 
    	for(int j = 0; j < H - i; j++)
    		printf(" ");
    	for(int j = 0; j < 2 * i - 1; j++)
    		printf("%c", C);
    	printf("\n");
	} 
    for(int i = 2; i <= H; i++) { //输出下半个沙漏 
    	for(int j = 0; j < H - i; j++)
			printf(" ");
		for(int j = 0; j < 2 * i - 1; j++)
			printf("%c", C);
		printf("\n"); 
	}
    printf("%d", N + 1 - 2 * H * H); //多余的字符 
    return 0;
}