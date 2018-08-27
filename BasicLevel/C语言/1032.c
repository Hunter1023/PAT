#include <stdio.h>

int main() {
	int N;
	scanf("%d", &N);
	int player[N+1];
	for (int i = 1; i < N+1; i++) {
		player[i] = 0;
	}
	while (N-- > 0) {
		int i = 0, grades = 0;
		scanf("%d %d", &i, &grades);
		player[i] += grades;
	}
	int max_index = 0, max = 0;
	for (int i = 1; i < sizeof(player)/ sizeof(int); i++) {
		if (player[i] > max) {
			max_index = i;
			max = player[i];
		}
	}
	printf("%d %d\n", max_index, max);
	return 0;
}