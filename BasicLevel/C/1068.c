/*
 * 1. 一定程度上考察对C语言的掌握
 * 2. 确定独一无二颜色的像素点
 *	2.1 颜色是一个 24 位的数值 —— 以像素数值为下标构造数组，通过计数判断独一无二
 *	2.2 即数组下标最大值 < 2^{25}，大数组要定义在main函数外，防止栈溢出
 * 3. 独一无二颜色的像素点，与其周围 8 个相邻像素的颜色差需要 > TOL
 * 	3.1 边界的像素周围不足8个相邻元素 —— 给边界像素外围再包一圈颜色为0的像素，将特殊情况一般化，统一判断
 *	3.2 像素点最多1000*1000个，外围包一圈则为1002*1002个
 *	3.3 周围颜色值存在更大或更小的情况，需要借助 abs() 函数，获取绝对值
 * 4. 输出要求的像素点的位置，x为列，y为行
 */
#include <stdio.h>
#include <math.h>

#define LEN 1002

int isUnique(int arr[][LEN], int x, int y, int TOL) {
	if (abs(arr[y][x] - arr[y-1][x-1]) <= TOL //左上 
		|| abs(arr[y][x] - arr[y][x-1]) <= TOL //左
		|| abs(arr[y][x] - arr[y+1][x-1]) <= TOL //左下 
		|| abs(arr[y][x] - arr[y-1][x]) <= TOL //上
		|| abs(arr[y][x] - arr[y-1][x+1]) <= TOL //右上 
		|| abs(arr[y][x] - arr[y][x+1]) <= TOL //右 
		|| abs(arr[y][x] - arr[y+1][x+1]) <= TOL //右下 
		|| abs(arr[y][x] - arr[y+1][x]) <= TOL) { //下
		return 0;
	}
	return 1;
} 
int arr[LEN][LEN] = {0};// 每个像素的颜色， 独一无二像素点的数量 
int pixel[2 << 24] = {0};// 2 << 24 即 2^25次方，能包括任意24位像素点
int main() {
	int M, N, TOL, cnt = 0;//图像的分辨率(列，行); 像素点与相邻点的颜色差阈值 
	scanf("%d %d %d", &M, &N, &TOL);
	for (int i = 1; i <= N; i++) {
		for (int j = 1; j <= M; j++) {
			scanf("%d", &arr[i][j]);
			pixel[arr[i][j]]++;//统计该像素点的数量 
		}
	}
	int x, y, color;//列、行，颜色值 
	for (int i = 1; i <= N; i++) {
		for (int j = 1; j <= M; j++) {
			if (pixel[arr[i][j]] == 1) {//该像素点只有一个 
				if (isUnique(arr, j, i, TOL)) {
					cnt++;
					x = j;
					y = i;
					color = arr[i][j];
					if (cnt == 2) {
						break;
					}
				}
			}
		}
		if (cnt == 2) {
			break;
		}
	}
	if (cnt == 2) {
		printf("Not Unique\n");
	} else if (cnt == 0) {
		printf("Not Exist\n");
	} else {
		printf("(%d, %d): %d", x, y, color);
	}
	return 0;
}