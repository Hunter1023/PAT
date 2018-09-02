/*
 * （与PAT字符有关的题目，可回顾一下 1003. 我要通过）
 * 1. 重点分析字母A ：
 *	 1.1 A前有P，后有T才能形成PAT；
 *	 1.2 A能构成的PAT数量 = 之前P的数量 * 之后T的数量
 * 2. 突破口：先遍历一遍，获取T的数量
 */
#include <stdio.h>
#include <string.h>

int main() {
	char str[100001];
	scanf("%s", str);
	long int cnt_p = 0, cnt_pat = 0, cnt_t = 0;
	for (int i = 0; i < strlen(str); i++) {
		if (str[i] == 'T') {
			cnt_t++; 
		} 
	}
	for (int i = 0; i < strlen(str); i++) {
		if(str[i] == 'P') {
			cnt_p++; 
		} else if (str[i] == 'A') {
			cnt_pat = (cnt_pat + (cnt_p * cnt_t) % 1000000007) % 1000000007;//时刻取余防止溢出 
		} else {
			cnt_t--;
			if(cnt_t == 0) {//之后无T，必然不会再形成PAT
				break;
			}
		}
	}
	printf("%d\n", cnt_pat);	
	return 0;
}