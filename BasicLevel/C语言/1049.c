/*
 * 1. 枚举法可以很容易得出每一位元素需要求和的数量为 i*(n-i+1)
 * 2. 求和时，上述公式很可能会溢出，因此将相乘时，将double类型的元素前置
 */
#include <stdio.h>

int main() {
    int N;
    scanf("%d", &N);
    double arr[N], sum = 0.0;
    for (int i = 0; i < N; i++) {
    	scanf("%lf", &arr[i]);
    	sum += arr[i] * (i+1) * (N-i);
	}
	printf("%.2f\n", sum);
    return 0;
}