#include <stdio.h>

int main() {
	int num, cnt = 0; //记录需要的步数 
	scanf("%d", &num);
	while (num != 1) {
		if (num % 2 == 0) { //是奇数
			num = 3*num + 1; 
		}
		num /= 2;
		cnt++;
	} 
	printf("%d", cnt);
	return 0;
} 