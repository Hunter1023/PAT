/* 将朋友证号作为数组下标 */
#include <stdio.h>

int main() {
	int N, isFriendId[37] = {0}, cnt = 0; // isFriendId 记录是否为朋友数（数字 < 10^4 则朋友数最大为36）
	scanf("%d", &N);
	for (int i = 0; i < N; i++) {
		int num, sum = 0;
		scanf("%d", &num); 
		while(num != 0) {
			sum += num % 10;
			num /= 10;
		}
		if(!isFriendId[sum]) {//如果该朋友证号还没有 
		    isFriendId[sum] = 1;//标记 
			cnt++;//记录不同朋友证号的数量 
		} 
	}
	printf("%d\n", cnt);
	for (int i = 1; cnt > 0 && i < 37; i++) {
		if (isFriendId[i]) {
			printf("%d", i);
			if (cnt-- != 1) {
				printf(" ");
			}
		}
	}
	printf("\n");
	return 0;
}