#include <cstdio>

int main() {
	double poly[1001] = {0}， coe; //多项式，系数
	int K, exp, cnt = 0; //输入的项数，指数，结果的项数 
	for(int i = 0; i < 2; i++) {
		scanf("%d", &K);
		cnt += K; //非零系数项的个数
		while(K--) {
			scanf("%d %lf", &exp, &coe);
			poly[exp] += coe;
			if(poly[exp] == 0) //系数抵消
				cnt--;
		}
	}
	printf("%d", cnt);
	for(int i = 1000; i >= 0; i--) {
		if(poly[i] != 0)
			printf(" %d %.1f", i, poly[i]);
	}
	return 0;
}