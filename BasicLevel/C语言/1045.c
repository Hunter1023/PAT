/*
 * 可能的主元：前面的最大值比自己小；后面的最小值比自己大
 * 将上述特征通过创建两个新数组来表现
 */
#include <stdio.h>

int main() {
    int N, cnt = 0;
    scanf("%d", &N);
    int arr[N], lmax[N], rmin[N];
    for(int i = 0; i < N; i++) {
    	scanf("%d", &arr[i]);
	}
	lmax[0] = arr[0];
	rmin[N-1] = arr[N-1];
    for(int i = 1; i < N; i++) {//找出在元素 左边最大的元素 
    	if (arr[i] > lmax[i-1]) {//如果当前元素>左边最大的元素 ,令当前元素左侧最大的元素为自身 
    		lmax[i] = arr[i];
		} else {
			lmax[i] = lmax[i-1];
		}
	}
    for(int i = N - 2; i >= 0; i--) {//找出在元素 右边最小的元素 
    	if (arr[i] < rmin[i+1]) {//如果当前元素 < 右边最小的元素 ,令当前元素右侧最大的元素为自身 
    		rmin[i] = arr[i];
		} else {
			rmin[i] = rmin[i+1];
		}
	}
    for(int i = 0; i < N; i++) {//统计可能是主元的数量 
        if(arr[i] == lmax[i] && arr[i] == rmin[i]) {//如果左侧最大的元素 和 右侧最小的元素 都是自身，就可能是主元 
        	cnt++;
		} else {
			arr[i] = 0;
		}
    }
    printf("%d\n", cnt);
    for(int i = 0; i < N && cnt > 0; i++) {
    	if(arr[i] != 0) {//可能是主元 
			printf("%d", arr[i]);
			if (cnt > 1) {
    			printf(" ");
			}
    		cnt--;
		}
	}
    printf("\n");
    return 0;
}