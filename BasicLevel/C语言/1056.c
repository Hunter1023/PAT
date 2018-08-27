#include <stdio.h>

int main(){
	int N;
	scanf("%d", &N);
	int num[N], sum = 0;
	for (int i = 0; i < N; i++) {
		scanf("%d", &num[i]);
	}
	for (int i = 0; i < N - 1; i++) {
		for (int j = i + 1; j < N; j++) {
			sum += num[i] * 10 + num[j];
			sum += num[j] * 10 + num[i];
		}
	}
	printf("%d\n", sum);
	return 0;
}