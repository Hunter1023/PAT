#include <cstdio>

int main() {
    int coe, exp, firstFlag = 1; //系数、指数 
    while(scanf("%d %d", &coe, &exp) != EOF) {
		if(exp != 0) { //常数项的导数不输出 
			if(!firstFlag)
				printf(" ");
			printf("%d %d", coe * exp, exp - 1);
			firstFlag = 0;
		}
	}
    if(firstFlag) //零多项式 
	   	printf("0 0");
    return 0;
}
