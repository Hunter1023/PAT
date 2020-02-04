#include <cstdio>

int main() {
	int T;
	long long i = 1;
	for (int j = 1; j <= 32; j++) {
		i *= 2;
	}
	printf("%lld\n", i);
	printf("%d", i);
	return 0; 
}
