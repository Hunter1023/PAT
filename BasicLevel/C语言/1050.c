/*
 * 1. 先对输入的数组排序
 * 2. 螺旋矩阵的行列数确定的关键：m−n 取所有可能值中的最小值，通过sqrt函数，开方再遍历，能最快地得到n
 * 3. 螺旋矩阵的填充顺序 上 → 右 → 下 → 左
 *	3.1 用二维数组存储螺旋矩阵
 *	3.2 遍历填充二维数组，以二维数组的圈数作为遍历的次数，分析可知圈数为 n / 2 + n % 2（n <= m，每少一圈，列数-2）
 *	3.3 注意填充之后，对未填充的最上行、最右列、最下行、最左列进行更新
 *  3.4 每遍历一次行/列后，判断是否已经遍历完所有数，跳出循环（避免后续的错误覆盖，时间的浪费）
 */
#include <stdio.h>
#include <stdlib.h>
#include <math.h>

int cmp(const void *a, const void *b) {//降序排序 
	return *(int *)b - *(int *)a;
}
int main(){
	int N, n, m;
	scanf("%d", &N);
	int  arr[N];
	for (int i = 0; i < N; i++){
		scanf("%d", &arr[i]);
	}
	qsort(arr, N, sizeof(int), cmp);
	for (int i = sqrt((double)N); i >= 1; i--) {
		if (N % i == 0) {
			n = i;
			break;
		}
	}
	m = N / n;
	int matrix[m][n]; 
	int urow = 0, drow = m - 1, lcol = 0, rcol = n - 1, i = 0;
	for (int k = n / 2 + n % 2; k >= 0; k--) { //从外到里遍历的圈数 
		for (int j = lcol; j <= rcol; j++, i++) {//遍历最上行 
			matrix[urow][j] = arr[i];
		}
		if (i == N) {
			break;
		}
		urow++;//第一层遍历完毕 
		for (int j = urow; j <= drow; j++, i++) {//遍历最右列 
			matrix[j][rcol] = arr[i];
		}
		if (i == N) {
			break;
		}
		rcol--;//最后一列遍历完毕 
		for (int j = rcol; j >= lcol; j--, i++) {//倒序遍历最下行 
			matrix[drow][j] = arr[i]; 
		}
		if (i == N) {
			break;
		}
		drow--;//最后一行遍历完毕 
		for (int j = drow; j >= urow; j--, i++) {//倒序遍历最左的列 
			matrix[j][lcol] = arr[i];
		} 
		if (i == N) {
			break;
		}
		lcol++;//最左列遍历完毕 
	} 
	for (int i = 0; i < m; i++) { //输出矩阵
		for (int j = 0; j < n; j++) {
			if (j == n - 1) {
				printf("%d\n", matrix[i][j]);
			} else {
				printf("%d ", matrix[i][j]);
			}
		}
	}
	return 0;
}