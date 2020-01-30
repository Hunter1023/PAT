/**
 * 本题重点在于 指数为0的项： 
 * 两种情况：
 * 1. 零多项式（只有一项），输出 0 0
 * 2. 非零多项式中的常数项，不输出
 */
#include <stdio.h>

int main() {
	int coe, index, isFirst = 1; //声明系数和指数，是否为多项式首项 
	do {
		scanf("%d %d", &coe, &index); //读取系数和指数 
		if (index != 0) { //输入的指数不为0 ， 指数为0时不输出 
			if (!isFirst) {
				printf(" ");
			}
			printf("%d %d", coe * index, index - 1); 
			isFirst = 0; //已有输出，不再是首项
		} 
	} while (getchar() != '\n');//遍历多项式，并能过滤空格 
	if (isFirst) {//如果仍然是首项，则读入了指数为0的单项式
		printf("0 0"); 		
	} 
	return 0; 
}