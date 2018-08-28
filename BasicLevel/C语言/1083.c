/* 遍历到末尾，如果差值相同 需要在循环外判断 */
#include <stdio.h>
#include <math.h>
#include <stdlib.h> 

int cmp(const void *a, const void *b) {//降序 
	return *(int *)b > *(int *)a;
}
int main() {
	int N;//N张卡片
	scanf("%d", &N);
	int arr[N];
	for (int i = 0; i < N; i++) {
		scanf("%d", &arr[i]);
		arr[i] = abs(arr[i] - i - 1);
	}
	qsort(arr, N, sizeof(int), cmp);
	int cnt = 1;
	for (int i = 0; i < N - 1; i++) {
		if (arr[i+1] == arr[i]) {
			cnt++;
		} else if (cnt > 1) {
			printf("%d %d\n", arr[i], cnt);
			cnt = 1;
		}
	}
	if (cnt > 1) {//如果最后的几个差值都相同 
		printf("%d %d\n", arr[N-1], cnt);
		cnt = 1;
	}
	return 0;
}