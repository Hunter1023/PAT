#include <stdio.h>

int main() {
	char str[4];
	while (scanf("%s", str) != EOF) {
		if (str[2] == 'T') {//是正确答案 
			printf("%d", str[0]- 'A' + 1);
		}
	}
	printf("\n");
	return 0;
}