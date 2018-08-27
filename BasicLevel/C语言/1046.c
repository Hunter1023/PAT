#include <stdio.h>

int main() {
    int N;
	scanf("%d", &N);
	int a_drink = 0, b_drink = 0;//甲乙喝酒的杯数 
	while (N-- > 0) {
		int a_num, a_sum, b_num, b_sum, sum;
		scanf("%d %d %d %d", &a_num, &a_sum, &b_num, &b_sum);
		sum = a_num + b_num;
		if (a_sum == sum && b_sum != sum) {
			b_drink++;
		} else if (a_sum != sum && b_sum == sum) {
			a_drink++;
		}
	}
	printf("%d %d\n", a_drink, b_drink);
    return 0;
}