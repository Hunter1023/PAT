#include <stdio.h>
#include <string.h>
#define LEN 100

int main() {
	int cnt_str = 0;
	scanf("%d", &cnt_str); //获取测试用例的个数

	while (cnt_str > 0) {
		char str[LEN]; // 用于储存字符串的数组	
		scanf("%s", str);
		
		int cnt_A = 0, cnt_P = 0, cnt_T = 0;
		int pos_P = 0, pos_T = 0; //设置P、T的下标 
		
		for (int i = 0; i < strlen(str); i++) {
			if (str[i] == 'P') {
				pos_P = i; //记录P的下标 
				cnt_P++;
			}else if (str[i] == 'A') {
				cnt_A++; //记录A的数量 
			}else if (str[i] == 'T') {
				pos_T = i; // 记录T的下标 
				cnt_T++;
			}
		}
		//如果字符串的长度是 P+A+T 
		if ( cnt_P + cnt_A + cnt_T == strlen(str)) {
			int l_A = 0, c_A = 0, r_A = 0; // 声明左、中、右 字符A的数量 
			l_A = pos_P;
			c_A = pos_T - pos_P - 1;
			r_A = strlen(str) - pos_T - 1;
			if (c_A > 0 && l_A * c_A == r_A) {// 如果A的数量 右=左*中 
				printf("%s\n", "YES");
				cnt_str--;
				continue;
			}
		}  
		printf("%s\n", "NO");
		cnt_str--;
	} 
	return 0;
} 