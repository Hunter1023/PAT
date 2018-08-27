/*
 * 1. 回文数本质就是左右对称的数，即倒置之后，和原来的值相同
 * 2. 运算过程中，数值可能会出现超过1000位的情况，要保证创建的字符数组大小足够
 * 3. 字符和数字之间的来回转换
 * 4. 最高位进位的处理，将原字符数组顺序后移一位
 */
#include <stdio.h>
#include <string.h>

int main() {
	char C[1012] = {0}, *arr;
	scanf("%s", C);
	int cnt = 0;
	while (cnt <= 10) {
		int len = strlen(C), flag = 0;// 数字的长度，是否有进位 
		char A[1012] = {0}, B[1012] = {0};
		for (int i = len - 1; i >= 0; i--) {
			A[i] = C[i];
			B[i] = C[len-1-i];
		} 
		if (!strcmp(A, B)) {//回文数实际就是左右对称的数 
			printf("%s is a palindromic number.", A);
			break;
		} else if (cnt == 10) {
			printf("Not found in 10 iterations.\n");
		} else {
			for (int i = len - 1; i >= 0; i--) {
				int sum = (A[i] - '0') + (B[i] - '0') + flag;
      			flag = sum / 10;
      			C[i] = sum % 10 + '0';
			}
			if(flag == 1){//最高位进位的情况
		    	for(int i = len; i > 0; i--) {//所有数字后移一位 
		    		C[i] = C[i - 1];
		    	}
		    	C[0] = 1 + '0';
		    }
			printf("%s + %s = %s\n", A, B, C);
		}
		cnt++;
	}
	return 0;
}