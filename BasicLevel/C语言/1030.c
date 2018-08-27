/*
 * 1. 用qsort函数排序时间复杂度低 
 * 	<stdlib.h> void qsort(void *base,size_t nelem,size_t width,int (*Comp)(const void *,const void *));
 * 2. 遍历时，高效地判断完美数列
 */
#include <stdio.h>
#include <stdlib.h>

int cmp(const void * a, const void * b) {
	//qsort的比较函数如果返回（第一个值大于第二个值时返回正数），则为递增 
	return *(long int *)a - *(long int *)b;
}
int main() {
	int N, max = 0;//正整数个数, 完美数列最多含有的数字个数 
	long int p;//参数p 
	scanf("%d %ld", &N, &p);
	long int arr[N];
	for (int i = 0; i < N; i++) {
		scanf("%ld", &arr[i]);
	} 
	//升序排序 
	qsort(arr, N, sizeof(long int),cmp);
	for (int i = 0; i < N; i++) {
		for (int j = i + max; j < N; j++) {// 超过最大数量的数列，是否为完美数列
			if(arr[j] <= (arr[i] * p)) {
				if (max < (j - i + 1)) {
					max = j - i + 1;
				}
			} else {//如果不是，后续元素更大，更不可能是，跳出循环即可
				break;
			}
		} 
	}
	printf("%d\n", max);
	return 0;
}