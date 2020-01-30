#include <stdio.h>
#include <stdlib.h>
#include <string.h>

int isPrime(int n) {
    if (n < 2) {
        return 0;
	}
    for (int i = 2; i * i <= n; i++) {
        if (n % i == 0) {
            return 0;
		}
	}
    return 1;
}

int main() {
	int L, K; //正整数的长度为L，寻找的素数为K位 
	scanf("%d %d\n", &L, &K);
	char num[L], tmp[10] = {0}; //tmp必须初始化，否则报错
	scanf("%s", num);
	for (int i = 0; i < L - K + 1; i++) {
		strncpy(tmp, num + i, K); //将字符串前K位复制到字符串tmp
		if (isPrime(atoi(tmp))) { // atoi(const char* str) 将字符串转换为int整数
			printf("%s", tmp);
			return 0;
		}
	}
	printf("404");
	return 0;
}
