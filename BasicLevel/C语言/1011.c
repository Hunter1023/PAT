#include <stdio.h>

int main() {
	long int A, B, C;//声明整数A B C; 如果A、B都是临界值会超过int型的范围，因此用long int型
	int T;//测试用例个数
	scanf("%d", &T);
	for (int i = 1; i <= T; i++) {
		scanf("%ld %ld %ld", &A, &B, &C);//读入整数
		if ((A + B) > C) {
			printf("Case #%d: true\n", i);
		} else {
			printf("Case #%d: false\n", i);
		}
	} 
	return 0; 
}