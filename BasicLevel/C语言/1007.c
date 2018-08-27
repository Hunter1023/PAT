#include <stdio.h>
#include <stdbool.h>

bool isprime(int num);
int main() {
	int num;
	scanf("%d", &num);
	int cnt = 0; //对满足条件的素数对计数 
	
	for( int i = 5; i <= num; i += 2) {//遍历从5开始的奇数 
		if(isprime(i) && isprime(i-2)) {// 如果相差2的两个奇数是素数 
			cnt++; 
		}
	}
	printf("%d", cnt);
	return 0; 
}
bool isprime(int num) {
	for (int i = 3; i * i <= num; i += 2) {//根据能否被 <= sqrt(i) 的奇数整除， 判断素数 
		if (num % i == 0) {// 能整除，不是素数 
			return false;
		} 
	}
	return true; 
}