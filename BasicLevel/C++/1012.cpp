#include <cstdio>

int main() {
	int N;
	scanf("%d", &N);
	int arr[N], A[6] = {0}, cntA[6] = {0};
	for (int i = 0; i < N; i++) {
		scanf("%d", &arr[i]);
		if (arr[i] % 10 == 0) { //能被5整除的偶数
			A[1] += arr[i];
			cntA[1]++;
		} else if (arr[i] % 5 == 1) { //被5除后余1 
			cntA[2]++;
			if (cntA[2] % 2 == 1) { //第奇数个 
				A[2] += arr[i]; 
			} else {
				A[2] -= arr[i];
			}
		} else if (arr[i] % 5 == 2) { //被5除后余2
			A[3]++;
			cntA[3]++;
		} else if (arr[i] % 5 == 3) { //被5除后余3
			A[4] += arr[i];
			cntA[4]++;
		} else if (arr[i] % 5 == 4 && A[5] < arr[i]) { //被5除后余4
			A[5] = arr[i];
			cntA[5]++; 
		}
	}
	for (int i = 1; i <= 5; i++) {
		if (cntA[i] == 0) {
			if (i != 1) {
				printf(" ");
			}
			printf("N");
		} else if (i == 1) {
			printf("%d", A[1]);
		} else if (i == 2 || i == 3 || i == 5) {
			printf(" %d", A[i]);
		} else { // i = 4
			printf(" %.1f", (double)A[i] / cntA[4]);
		}
	} 
	printf("\n");
	return 0; 
}