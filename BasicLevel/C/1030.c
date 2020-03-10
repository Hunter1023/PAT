/*
 * 如何高效地判断完美数列：
 *  1. 快速排序
 *  2. 遍历数组，判断 比当前已知的最长完美数列 更长的数列 是否为完美数列
 */
#include <stdio.h>
#include <stdlib.h>

int cmp(const void *a, const void *b) {
	return *(long long *)a - *(long long *)b; //升序,(返回值>0，a 被排在后面)
}

int main() {
	int N, p;
	scanf("%d %d", &N, &p);
	long long arr[N];
	for(int i = 0; i < N; i++)
		scanf("%lld", &arr[i]);
	qsort(arr, N, sizeof(long long), cmp); //升序排序
	int maxCnt = 0; //正整数个数, 完美数列最多含有的数字个数 
	for(int i = 0; i + maxCnt < N; i++) { //数列未取完
		for(int j = i + maxCnt; j < N; j++) { //超过完美数列数字个数，是否为完美数列
			if(arr[j] <= (arr[i] * p)) {
				maxCnt++;
			} else { //如果不是，后续元素更大，更不可能是，跳出循环即可
				break;
			}
		} 
	}
	printf("%d\n", maxCnt);
	return 0;
}