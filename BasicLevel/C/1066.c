#include <stdio.h>

int main() {
	int M, N, A, B, gray, temp;
	scanf("%d %d %d %d %d", &M, &N, &A, &B, &gray);
	for (int i = 0; i < M; i++) {
		for (int j = 0; j < N; j++) {
			scanf("%d", &temp);
			if (temp >= A && temp <= B) {
				temp = gray;
			}
			if (j != 0) {
				printf(" ");
			}
			printf("%03d", temp);
		}
		printf("\n");
	}
	return 0;
}