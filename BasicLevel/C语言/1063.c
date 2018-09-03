#include <stdio.h>
#include <math.h>

int main(){
	int N;//特征值个数
	scanf("%d", &N);
	double max = 0.0;
	for (int i = 0; i < N; i++) {
		int a, b, sum;
		scanf("%d %d", &a, &b);
		sum = a * a + b * b; 
		if (sum > max) {
			max = sum;
		}
	}
	printf("%.2f", sqrt(max));
	return 0;
}