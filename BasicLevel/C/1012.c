#include <stdio.h>

int main() {
	int N, num, A1 = 0, A2 = 0, A3, A5 = 0;
	int cnt[5] = {0, 0, 0, 0, 0}, isOdd = 1; //统计符合各分类的数字数量；是否为奇数 
	double A4 = 0.0;
	scanf("%d", &N);//读取整数数量
	while (N-- > 0) {
		scanf("%d", &num);//读取数字
		if (num % 10 == 0) {//被5整除的数字中的偶数 
			cnt[0]++;
			A1 += num; 
		} else if (num % 5 == 1) {//余1
			cnt[1]++; 
			if (isOdd) {//第奇数个，加上 
				A2 += num;
				isOdd = false;
			} else {//第偶数个，减去 
				A2 -= num;
				isOdd = true;
			}
		} else if (num % 5 == 2) {
			cnt[2]++;
		} else if (num % 5 == 3) {
			A4 += num;
			cnt[3]++;
		} else if (num % 5 == 4 && num > A5) {
			A5 = num;
			cnt[4]++;
		} 
	}
	for (int i = 0; i < 5; i++) {
		if (i != 0) {
			printf(" ");
		} 
		if (cnt[i] ==0) {
			printf("N");
		} else if (i == 0) {
			printf("%d", A1);
		} else if (i == 1) {
			printf("%d", A2);
		} else if (i == 2) {
			printf("%d", A3 = cnt[2]);
		}else if (i == 3) {
			A4 /= cnt[3];
			printf("%.1f", A4);
		} else {
			printf("%d", A5);
		}
	} 
	return 0; 
}