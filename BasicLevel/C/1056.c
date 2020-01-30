#include <stdio.h>

int main(){
	int N;
	scanf("%d", &N);
	int num, sum = 0;
	for (int i = 0; i < N; i++) {
		scanf("%d", &num);
		sum += num * 10 * (N-1) + num * (N-1);//其他数字在个位的数有N-1个，自身在个位的数有N-1个
	}
	printf("%d\n", sum);
	return 0;
}