/* 数组大小的定义需要满足 求第40项时的数值长度，采用暴力估值定义 */
#include <stdio.h>

int main() {
	int d, N;//数字d，第N项
	scanf("%d %d", &d, &N);
	int arr[100000], result[100000];//取较大值，防止溢出 
	int length = 1; //当前项的位数
	arr[0] = d;//第一项  
	for (int j = 1; j < N; j++) { //循环N-1次得到第N项 
		int i = 0;
		for (int k = 0; k < length; k++) {
			result[i++] = arr[k];//记录数值 
			int cnt = 1;
			while (k + 1 < length && arr[k] == arr[k + 1]) {//统计相邻的相同数字的数量 
				cnt++;
				k++;
			} 
			result[i++] = cnt;
		}
		length = i;
		for (int k = 0; k < length; k++) {
				arr[k] = result[k];
		}
	}
	for (int i = 0; i < length; i++) {
		printf("%d", arr[i]);
	}
	return 0;
}