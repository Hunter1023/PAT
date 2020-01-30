#include <stdio.h>
 
int main() { 
	int M, N, K;
	scanf("%d", &M);
	while (M--) {
        scanf("%d", &K); //读入整数K
		int power = 1, tmp = K;
		while (tmp) {//确定整数K的位数
            power *= 10; 
            tmp /= 10;
        }
		for (N = 1; N < 10; N++) {
            tmp = N * K * K;
            if (tmp % power == K) {
                printf("%d %d\n", N, tmp);
                break;
            }
        }
        if (N == 10) {
            printf("No\n");
		}
    }
    return 0;
}