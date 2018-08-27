#include <stdio.h>

int main() {
	int P[3], A[3];
	scanf("%d.%d.%d %d.%d.%d", &P[0], &P[1], &P[2], &A[0], &A[1], &A[2]);
	int isenough = 1;
	if (A[0] * 17 * 29 + A[1] * 29 + A[2] - P[0] * 17 * 29 - P[1] * 29 - P[2] < 0) {//钱不够 
		printf("-");
		for (int i = 0; i < 3; i++) {
			int temp = P[i];
			P[i] = A[i];
			A[i] = temp;
		} 
	}
	int remain[3];
	if (A[2] - P[2] < 0) {
		A[2] += 29;
		A[1]--;
	}
	remain[2] = A[2] - P[2];
	if (A[1] - P[1] < 0) {
		A[1] += 17;
		A[0]--;
	}
	remain[1] = A[1] - P[1];
	remain[0] = A[0] - P[0];
	printf("%d.%d.%d\n", remain[0], remain[1], remain[2]);
	return 0;
}