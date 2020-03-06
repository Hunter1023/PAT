#include <cstdio>

int main() {
    int A, B, D, sum, ans[31], index = 0; //结果最长为2进制的2^31-2，占31位
    scanf("%d %d %d", &A, &B, &D);
    sum = A + B;
	do {
		ans[index++] = sum % D;
		sum /= D;
	} while(sum != 0);
	for(int i = index - 1; i >= 0; i--)
		printf("%d", ans[i]);
    return 0;
}