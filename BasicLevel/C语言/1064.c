/* 待优化 */
#include <stdio.h>
#include <stdlib.h>

int cmp(const void *a, const void *b) {//升序排序 
	return *(int *)a > *(int *)b;
}
int main() {
	int N;//
	scanf("%d", &N);
	int id[N];
	for (int i = 0; i < N; i++) {
		int num;
		scanf("%d", &num); 
		id[i] = 0;
		while(num % 10 != 0) {
			id[i] += num % 10;
			num /= 10;
		}
	}
	qsort(id, N, sizeof(int), cmp);
	int cnt = 0, friendId = 0;
	for (int i = 0; i < N; i++) {
		if (id[i] != friendId) {
			friendId = id[i];
			cnt++;
		}
	} 
	printf("%d\n", cnt);
	friendId = 0;
	for (int i = 0; cnt > 0 && i < N; i++) {
		if (id[i] != friendId) {
			printf("%d", id[i]);
			friendId = id[i];
			if (cnt != 1) {
				printf(" ");
			}
			cnt--;
		}
	}
	printf("\n");
	return 0;
}