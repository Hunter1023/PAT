#include <cstdio>

int main() {
	long long num[2], P[2] = {0};
	int  D[2];
	scanf("%lld %d %lld %d", &num[0], &D[0], &num[1], &D[1]);
	for (int i = 0; i < 2; i++) {
		while (num[i] != 0) {
			if (num[i] % 10 == D[i]) {
				P[i] = P[i] * 10 + D[i];
			}
			num[i] /= 10;
		}
	}
	printf("%lld\n", P[0] + P[1]);
	return 0; 
}
