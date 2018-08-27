#include <stdio.h>
#include <stdbool.h>

bool isprime(int num);
int main() {
	int M, N; //第M和第N个素数 
	scanf("%d %d", &M, &N);
	int cnt = 1; //对已经获取到的素数计数
	int prime1 = 2, prime2 = 3;// 创建第一个素数2，第二个素数3 
	while (cnt <= N) {
		if (cnt >= M) {
			printf("%d", prime1);
			if (cnt != N && (cnt - M + 1) % 10 != 0) {
				printf(" ");
			} else {
				printf("\n");
			}
		} 
		prime1 = prime2; // 获取下一个素数
		cnt++; 
		do {
			prime2 +=2;
		} while (!isprime(prime2));
	} 
	return 0; 
}
bool isprime(int num) {//判断从5开始的奇数是否为素数 
	for (int i = 3; i * i <= num; i += 2) {//根据能否被 <= sqrt(i) 的奇数整除， 判断素数 
		if (num % i == 0) {// 能整除，不是素数 
			return false;
		} 
	}
	return true; 
}