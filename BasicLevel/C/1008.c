/*
 * 1. 元素循环右移M位 可以转化为以下三步：
 *		1. 元素全部倒置；
 *		2. 前M个元素倒置；
 *		3. 之后的所有元素倒置；
 * 2. 数组部分元素倒置：可用数组下标标记 倒置范围
 * 3. 若右移的位数M超出元素数量N，等同于 右移 M % N 位
 */
#include <stdio.h>

void reverse(int *arr, int left, int right) {//倒置数组中部分元素的函数，参数依次为 数组，起始下标，终止下标
	int temp;
	for (int i = 0; i < (right - left + 1) / 2; i++) { 
		temp = arr[left+i];
		arr[left+i] = arr[right-i];
		arr[right-i] = temp; 
	}
} 
int main() {
	int N, M;//数组大小，右移位数 
	scanf("%d %d", &N, &M); 
	int arr[N];//创建数组 
	M = M % N;// 使 M < N，避免出错，达到同样的位移结果 
	for (int i = 0; i < N; i++) {//读入数字 
		scanf("%d", &arr[i]); 
	} 
	reverse(arr, 0, N-1);//倒置数组 
	reverse(arr, 0, M-1);//倒置前d个数 
	reverse(arr, M, N-1);//倒置之后的所有数  
	for (int i = 0; i < N; i++) {//输出
		if (i != 0) {
			printf(" ");
		}
		printf("%d", arr[i]);
	} 
	return 0; 
}