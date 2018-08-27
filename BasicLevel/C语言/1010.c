#include <stdio.h>
#include <stdbool.h>

int main() {
	int coe, index;//声明系数和指数 
	bool isfirst = true;//是否为多项式首项 
	do {
		scanf("%d %d", &coe, &index);//读取系数和指数 
		if (index != 0) {//输入的指数不为0 ， 指数为0时不输出 
			if (!isfirst) {
				printf(" ");
			}
			printf("%d %d", coe * index, index - 1); 
			isfirst = false; 
		} 
	} while (getchar() != '\n');//遍历多项式，并能过滤空格 
	if (isfirst) {//如果是首项，指数必为0
		printf("0 0"); 		
	} 
	return 0; 
}