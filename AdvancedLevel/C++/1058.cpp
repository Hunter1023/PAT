#include <cstdio>

int main() {
	long long A, B, sum, Ga, Si, Kn;
	scanf("%lld.%lld.%lld", &Ga, &Si, &Kn);
	A = (Ga * 17 + Si) * 29 + Kn; //转换过程中可能超过int范围 
	scanf("%lld.%lld.%lld", &Ga, &Si, &Kn);
	B = (Ga * 17 + Si) * 29 + Kn;
	sum = A + B;
	printf("%d.%d.%d", sum / 29 / 17, sum / 29 % 17, sum % 29);
    return 0;
}