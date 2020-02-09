#include <cstdio>

int main() {
	double poly[1001] = {0}, pro[2001] = {0}, coe;
	int K, exp, cnt = 0; //输入的项数，指数，结果的项数 
	scanf("%d", &K);
	while(K--) {
		scanf("%d %lf", &exp, &coe);
		poly[exp] = coe;
	}
	scanf("%d", &K);
	while(K--) {
		scanf("%d %lf", &exp, &coe);
		for(int i = 0; i <= 1000; i++) {
			if(poly[i] != 0)
				pro[i + exp] += coe * poly[i];
		}
	}
	for(int i = 0; i <= 2000; i++) {
		if(pro[i] != 0)
			cnt++;
	}
	printf("%d", cnt);
	for(int i = 2000; i >= 0; i--) {
		if(pro[i] != 0)
			printf(" %d %.1f", i, pro[i]);
	}
	return 0;
}