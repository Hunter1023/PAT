#include <stdio.h>

int main() {
	int num;
	int cnt = 0; //记录需要的步数 
	scanf("%d", &num);
	while (num != 1) {
		if (num % 2 == 0) { //如果n是偶数 
			num /= 2; 
		} else {
			num = (3*num + 1) / 2;
		}
		cnt++;
	} 
	printf("%d", cnt);
	return 0;
} 