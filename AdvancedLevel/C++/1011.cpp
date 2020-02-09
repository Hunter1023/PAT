#include <cstdio>

int main() {
	double odds[3], max[3] = {0}, pro = 1;
	char choose[4] = "WTL", best[3];
	for(int i = 0; i < 3; i++) {
		for(int j = 0; j < 3; j++) {
			scanf("%lf", &odds[j]);
			if(odds[j] > max[i]) {
				max[i] = odds[j];
				best[i] = choose[j % 3];
			}
		}
		pro *= max[i];
		pirintf("%c ", best[i]);
	} 
	printf("%.2f", (pro * 0.65 - 1) * 2);
	return 0;
}