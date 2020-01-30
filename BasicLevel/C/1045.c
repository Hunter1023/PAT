/*
 * 1. 可能的主元：前面的最大值比自己小；后面的最小值比自己大
 * 2. 解题关键：将原数组 与 升序排序后的数组 比较
 * 		相同下标的元素仍然相同，且左边最大值比自身小 即可能为主元 
 */
#include <stdio.h>
#include <stdlib.h>

int cmp(const void *a, const void *b) {
	return *(int *)a > *(int *)b;//升序 
} 
int main() {
    int N;//元素数量
    scanf("%d", &N);
    int arr[N], rank[N], c[N];//读入的数组，排序后的数组，主元数组 
    for(int i = 0; i < N; i++) {
    	scanf("%d", &arr[i]);
    	rank[i] = arr[i];
	}
	qsort(rank, N, sizeof(int), cmp);//升序排序 
	int cnt = 0, max = 0;//主元个数，左边最大的值 
	for (int i = 0; i < N; i++) {
		if(arr[i] == rank[i] && arr[i] > max) {//排序后，相同下标的元素仍然相同，且左边最大值比自身小 
        	c[cnt++] = arr[i];//记录该 可能的主元 
		}
        if (arr[i] > max) {//更新左边最大值 
        	max = arr[i];
		}
	}
    printf("%d\n", cnt);
    for(int i = 0; i < cnt; i++) {
    	if (i != 0) {
    		printf(" ");
		}
		printf("%d", c[i]);
	}
    printf("\n");
    return 0;
}