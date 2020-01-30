/*
 * (3n+1)猜想 的循环计算条件是 数字 != 1 
 * 不能被数列中的其他数字所覆盖为“关键数” ----> 能被覆盖的数最终也会变成1；
 * 即 遍历数列，将非关键数改为1后，剩下的就是关键数。
 */
#include <stdio.h>
#include <stdlib.h>

int cmp(const void *a, const void *b) {//降序
	return *(int *)b > *(int *)a;
}
int main() {
    int K; //正整数的数量 
    scanf("%d",&K);
    int arr[K]; //创建存放数字的数组 
    for (int i = 0; i < K; i++) {
        scanf("%d", &arr[i]);
    }
    for (int i = 0; i < K; i++) { //筛选关键数字
        int num = arr[i];
        while (num != 1) {//进行(3n+1)猜想
            if(num % 2 == 0) {
				num /= 2;
			} else {
				num = (3*num + 1) / 2;
			}
            for (int j = 0; j < K; j++) {//遍历数组，如果是被覆盖的数，变为1
                if (arr[j] == num) {
                    arr[j] = 1;
                    break;// 因为数组的数字各不相同，找到被覆盖的即可跳出循环
                }
            }
        }
    } 
	qsort(arr, K, sizeof(int), cmp); // 快速排序
	for (int i = 0; arr[i] != 1 && i < K; i++) { //输出关键字 
		if(i != 0) {
			printf(" ");
		}
		printf("%d", arr[i]); 
	} 
}