﻿/*
 * 数组下标作为需要判断的数，memset初始化数组各元素大小为 -1，表示没有判断过
 * 不能被数列中的其他数字所覆盖为“关键数”，标记为1；能被覆盖的 标记为 0；
 * 遍历数列，标记为1的为关键数。
 */
#include <stdio.h>
#include <string.h>

int main() {
	int K, isKey[101], num;
	memset(isKey, -1, sizeof(isKey));
	scanf("%d", &K);
	while(K--) {
		scanf("%d", &num);
		if(isKey[num] == -1) {//还未判断过 
			isKey[num] = 1; //关键数
			while(num != 1) {
				if(num % 2 == 1) //奇数 
					num = 3 * num + 1;
				num /= 2;
				if(num <= 100) //奇数可能会超过100 
					isKey[num] = 0;	//非关键数
			}
		}
	}
	int isFirst = 1;
	for(int i = 100; i > 1; i--) {
		if(isKey[i] == 1) {
			if(!isFirst)
				printf(" ");
			printf("%d", i);
			isFirst = 0;
		}
	}
	return 0;
} 