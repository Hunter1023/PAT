/*
 * 本题的关键：
 * 1. 第i个素数的获取方法：遍历奇数，记录素数的个数
 * 2. 素数的输出，10 个数字占 1 行，末尾无空格：记录已输出的数量
 */
#include <stdio.h>

int isPrime(int num) {//判断从5开始的奇数是否为素数 
	for (int i = 3; i * i <= num; i += 2) {//根据能否被 <= sqrt(i) 的奇数整除， 判断素数 
		if (num % i == 0) {// 能整除，不是素数 
			return 0;
		} 
	}
	return 1; 
}
int main() {
	int M, N; //第M和第N个素数 
	scanf("%d %d", &M, &N);
	int cnt = 1, prime1 = 2, prime2 = 3; //对已经获取到的素数计数；创建第一个素数2，第二个素数3 
	while (cnt <= N) {
		if (cnt >= M) {//输出 P_M 到 P_N 之间的素数
			printf("%d", prime1);
			if (cnt != N && (cnt - M + 1) % 10 != 0) {//不是最后一个，也不是一行的末尾
				printf(" ");
			} else {
				printf("\n");
			}
		} 
		prime1 = prime2; // 获取下一个素数
		cnt++; //统计素数的数量
		do {
			prime2 += 2;
		} while (!isPrime(prime2));
	} 
	return 0; 
}