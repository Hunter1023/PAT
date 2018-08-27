#include <stdio.h>

void reverse(int *arr, int left, int right); 
int main() {
	int size, d;//声明数组大小和右移 
	scanf("%d %d", &size, &d); 
	int arr[size];//创建数组 
	d = d % size;// 使 d < size，避免出错，达到同样的位移结果 
	for (int i = 0; i < size; i++) {//读入数字 
		scanf("%d", &arr[i]); 
	} 
	reverse(arr, 0, size-1);//倒置数组 
	reverse(arr, 0, d-1);//倒置前d个数 
	reverse(arr, d, size-1);//倒置之后的所有数 
	//输出 
	for (int i = 0; i < size; i++) {
		if(i != 0) {
			printf(" ");
		}
		printf("%d", arr[i]);
	} 
	return 0; 
}
void reverse(int *arr, int left, int right) {//倒置数组中部分元素的函数，参数依次为 数组，起始下标，终止下标
	int temp;
	for (int i = 0; i < (right - left + 1) / 2; i++) { 
		temp = arr[left+i];
		arr[left+i] = arr[right-i];
		arr[right-i] = temp; 
	}
}