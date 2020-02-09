#include <cstdio>

int main() {
	int K, order[55] = {0}; //重复次数
	char suit[6] = "SHCDJ";
	scanf("%d", &K);
	int card[K+1][55] = {0};
	for(int i = 1; i <= 54; i++) {
		card[0][i] = i;
		scanf("%d", &order[i]);
	}
	for(int i = 1; i <= K; i++) {
		for(int j = 1; j <= 54; j++)
			card[i][order[j]] = card[i-1][j];
	}
	for(int i = 1; i <= 54; i++) {
		if(i != 1)
			printf(" ");
		card[K][i]--; //便于后续转换
		printf("%c%d", suit[card[K][i] / 13], card[K][i] % 13 + 1);
	}
	return 0;
}