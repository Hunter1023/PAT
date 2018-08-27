#include <stdio.h>

int main() {
	long int num[2] = {0,0}, num_P[2] = {0,0}, cnt_D[2] = {1,1};
	int num_D[2] = {0,0};
	scanf("%ld %d %ld %d", &num[0], &num_D[0], &num[1], &num_D[1]);
	for (int i = 0; i < 2; i++) {
		while( num[i] > 0) {//当数字不为0时 
			if (num[i] % 10 == num_D[i]) {//如果有位数是D 
				num_P[i] +=  num_D[i]*cnt_D[i];//更新整数P
				cnt_D[i] *= 10;//更新位数 
			}
			num[i] /= 10;
		}
	}
	printf("%ld\n", num_P[0] + num_P[1]); 
	return 0; 
}