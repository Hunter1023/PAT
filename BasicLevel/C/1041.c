/* 将试机号作为数组下标 */
#include <stdio.h>
#include <string.h>

typedef struct {
	char examNum[15];//准考证号
	int seatNum;//座位号 
} examiee;
int main() {
	int N;//考生人数
	scanf("%d", &N);
	examiee arr[N];
	for (int i = 0; i < N; i++) {
		char num1[15];//准考证号
		int testNum, num3;//试机号，座位号 
		scanf("%s %d %d", num1, &testNum, &num3);
		strcpy(arr[testNum-1].examNum, num1);
		arr[testNum-1].seatNum = num3;
	} 
	int M, num;//待查的数量, 试机号 
	scanf("%d", &M);
	while (M-- > 0) {
		scanf("%d", &num);
		printf("%s %d\n", arr[num-1].examNum, arr[num-1].seatNum);
	}
	return 0;
}