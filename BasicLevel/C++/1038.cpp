#include <cstdio>

int main() {
	int N, scores, cnt[101] = {0}, K;
	scanf("%d", &N);
	while (N--) {
		scanf("%d", &scores);
		cnt[scores]++;
	}
	scanf("%d", &K);
	while (K--) {
		scanf("%d", &scores);
		printf("%d", cnt[scores]);
		if (K != 0) {
			printf(" ");
		}
	}
	return 0; 
}
