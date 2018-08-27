#include <stdio.h>

int main() {
	long int A, B, C;//声明整数A B C; 如果AB都是临界值会超过int型的范围，因此用long int型
	int cnt;//测试用例的个数
	scanf("%d", &cnt);
	for (int i = 1; i <= cnt; i++) {
		scanf("%ld %ld %ld", &A, &B, &C);//读入整数
		if ((A + B) > C) {
			printf("Case #%d: true\n", i);
		} else {
			printf("Case #%d: false\n", i);
		}
	} 
	return 0; 
}