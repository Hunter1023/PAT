#include <cstdio>

int main() {
	int T;
	scanf("%d", &T);
	for(int i = 1; i <= T; i++) {
		long long A, B, C;
		scanf("%lld %lld %lld", &A, &B, &C);
		printf("Case #%d: %s\n", i, A + B > C ? "true" : "false");
	} 
	return 0; 
}