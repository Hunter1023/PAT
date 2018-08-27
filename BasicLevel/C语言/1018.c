#include <stdio.h>

int main() {
	int N, Awin = 0, Alose = 0;
	char A, B;
	int cnt_A[3] = {0}, cnt_B[3] = {0};//统计各手势获胜的次数 
	scanf("%d", &N); 
	for (int i = 0; i < N; i++) {
		scanf("\n%c %c", &A, &B); // 注意%c，会将回车、空格、空格读入 
		if (A == 'B' && B == 'C') {// 注意手势计数下标要正确 
			Awin++;
			cnt_A[0]++;
		} else if (A == 'B' && B == 'J') {
			Alose++;
			cnt_B[2]++;
		} else if (A == 'C' && B == 'J') {
			Awin++;
			cnt_A[1]++;
		} else if (A == 'C' && B == 'B') {
			Alose++;
			cnt_B[0]++;
		} else if (A == 'J' && B == 'B'){
			Awin++;
			cnt_A[2]++;
		} else if (A == 'J' && B == 'C') {
			Alose++;
			cnt_B[1]++;
		} 
	}
	printf("%d %d %d\n", Awin, N - Awin - Alose, Alose);
	printf("%d %d %d\n", Alose, N - Awin - Alose, Awin);
	int maxA = (cnt_A[1] >= cnt_A[2]) ? 1 : 2;
	maxA = (cnt_A[0] >= cnt_A[maxA]) ? 0 : maxA; 
	int maxB = (cnt_B[1] >= cnt_B[2]) ? 1 : 2;
	maxB = (cnt_B[0] >= cnt_B[maxB]) ? 0 : maxB; 
	char str[4] = {"BCJ"};
	printf("%c %c\n", str[maxA], str[maxB]); 
	return 0; 
}