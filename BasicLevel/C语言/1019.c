#include <stdio.h>

int calculate(int num, int *arr, int len);
int main() {
	int num;
	scanf("%d", &num);
	int arr[4] = {0};//数组
	int result = 0;
	do {
		result = calculate(result, arr, 4);
	} while (result != 0 && result != 6174); 
	return 0; 
}
int calculate(int num, int *arr, int len) {
	int i = 0, max = 0, min = 0;//数组下标，最大值，最小值 
	while (num / 10 != 0 || num % 10 != 0) { 
		arr[i++] = num % 10;
		num /= 10;
	} 
	for (int i = 0; i < len - 1; i++) {//降序排序 
		for (int j = 0; j < len - i - 1; j++) {
			if (arr[j] < arr[j+1]) {
				int temp = arr[j];
				arr[j] = arr[j+1];
				arr[j+1] = temp;
			}
		} 
	}
	max = arr[0] * 1000 + arr[1] * 100 + arr[2] * 10 + arr[3];
	min = arr[0] + arr[1] * 10 + arr[2] * 100 + arr[3] * 1000;
	int result = max - min;
	if (result == 0) {
		printf("%04d - %04d = 0000\n", max, min);
	} else {
		printf("%04d - %04d = %04d\n", max, min, result);
	}
	return result;
}