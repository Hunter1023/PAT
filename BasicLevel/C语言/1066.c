#include <stdio.h>

int main() {
	int M, N, A, B, gray;
	scanf("%d %d %d %d %d", &M, &N, &A, &B, &gray);
	int arr[M][N];//M行N列
	for (int i = 0; i < M; i++) {
		for (int j = 0; j < N; j++) {
			scanf("%d", &arr[i][j]);
		}
	}
	for (int i = 0; i < M; i++) {
		for (int j = 0; j < N; j++) {
			if (arr[i][j] >= A && arr[i][j] <= B) {
				arr[i][j] = gray;
			}
			if (j != 0) {
				printf(" ");
			}
			printf("%03d", arr[i][j]);
		}
		printf("\n");
	}
	return 0;
}