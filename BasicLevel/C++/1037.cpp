#include <cstdio>

int main() {
	long long Galleon, Sickle, Knut, P, A, change; //转换过程中可能超过int范围
	scanf("%lld.%lld.%lld", &Galleon, &Sickle, &Knut);
	P = (Galleon * 17 + Sickle) * 29 + Knut; //价钱 
	scanf("%lld.%lld.%lld", &Galleon, &Sickle, &Knut);
	A = (Galleon * 17 + Sickle) * 29 + Knut; //实付 
	change = A - P; 
	if(change < 0) {//钱不够 
		printf("-");
		change = -change;
	}
	printf("%d.%d.%d\n", change / 29 / 17, change / 29 % 17, change % 29);
	return 0;
}