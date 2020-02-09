#include <stdio.h>

int main() {
	int N, Awin = 0, Bwin = 0, // 交锋次数，A和B赢的次数
		cntA[3] = {0}, cntB[3] = {0}; //按“CJB”顺序，记录各手势获胜的次数 
	char A, B, str[4] = "CJB";
	scanf("%d", &N);
	for(int i = 0; i < N; i++) {
		getchar(); //读取scanf留在缓冲区的换行符  
		scanf("%c %c", &A, &B);
		if(A == 'C' && B == 'J') { //A锤子赢
			Awin++;
			cntA[0]++;
		} else if(A == 'J' && B == 'B') { //A剪刀赢
			Awin++;
			cntA[1]++;
		} else if(A == 'B' && B == 'C') { //A布赢
			Awin++;
			cntA[2]++;
		} else if(B == 'C' && A == 'J') { //B锤子赢
			Bwin++;
			cntB[0]++;
		} else if(B == 'J' && A == 'B') { //B剪刀赢
			Bwin++;
			cntB[1]++;
		} else if(B == 'B' && A == 'C') { //B布赢
			Bwin++;
			cntB[2]++;
		} 
	}
	printf("%d %d %d\n", Awin, N - Awin - Bwin, Bwin);
	printf("%d %d %d\n", Bwin, N - Awin - Bwin, Awin);
	int maxA = (cntA[0] >= cntA[1]) ? 0 : 1;
	maxA = (cntA[2] >= cntA[maxA]) ? 2 : maxA; 
	int maxB = (cntB[0] >= cntB[1]) ? 0 : 1;
	maxB = (cntB[2] >= cntB[maxB]) ? 2 : maxB;
	printf("%c %c\n", str[maxA], str[maxB]); 
	return 0; 
}