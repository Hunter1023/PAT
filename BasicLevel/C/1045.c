#include <stdio.h>
#include <string.h>

int main() {
    int N;
    scanf("%d", &N);
    int arr[N], ans[N], leftMax[N], rightMin[N];
    memset(leftMax, 0, sizeof(int));
	rightMin[N-1] = 1e9 + 1; //初始化最后一个元素的右侧最小值
    for(int i = 0; i < N; i++) {
    	scanf("%d", &arr[i]);
		if(i > 0) //确定每个元素左侧的最大值
			leftMax[i] = arr[i-1] > leftMax[i-1] ? arr[i-1] : leftMax[i-1];
	}
	for(int i = N - 2; i >= 0; i--) //确定每个元素的右侧最小值 
		rightMin[i] = arr[i+1] < rightMin[i+1] ? arr[i+1] : rightMin[i+1];
	int cnt = 0;
	for(int i = 0; i < N; i++) { 
		if(arr[i] > leftMax[i] && arr[i] < rightMin[i]) //符合要求的元素必然为递增顺序 
			ans[cnt++] = arr[i];
	}
	printf("%d\n", cnt);
	for(int i = 0; i < cnt; i++) {
		if(i > 0)
			printf(" "); 
		printf("%d", ans[i]);
	}
	printf("\n"); //即使没有主元，也得换行 
    return 0;
}