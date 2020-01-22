#include <stdio.h>

int main() {
	int N, max = -1, result, cnt = 0;
	scanf("%d", &N);
	for (int i = 0; i <= N; i++) {
		result = i / 2 + i / 3 + i / 5;
		if (result > max) {
			max = result;
			cnt++;
		}
	} 
	printf("%d", cnt);
	return 0;
}
