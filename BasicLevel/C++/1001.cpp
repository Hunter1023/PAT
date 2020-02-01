#include <cstdio> 

int main() {
	int n, cnt = 0; //给定的数，需要的步数 
	scanf("%d", &n);
	while (n != 1) {
		if (n % 2 != 0) { //是奇数
			n = 3*n + 1; 
		}
		n /= 2;
		cnt++;
	} 
	printf("%d", cnt);
	return 0;
}
