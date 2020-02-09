#include <cstdio>

int main() {
	int N, cup[2] = {0}; //划拳的次数，甲、乙喝的杯数
	scanf("%d", &N);
	while(N--) {
		int numA, sumA, numB, sumB;
		scanf("%d %d %d %d", &numA, &sumA, &numB, &sumB);
		int sum = numA + numB; //喊的数字之和
		if(sumA != sumB && sumA == sum) { //甲赢
			cup[1]++;
		} else if(sumA != sumB && sumB == sum) { //乙赢
			cup[0]++;
		}
	}
	printf("%d %d\n", cup[0], cup[1]);
	return 0;
}