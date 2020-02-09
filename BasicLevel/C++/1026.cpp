#include <cstdio>
#include <cmath>
#define CLK_TCK 100

int main() {
	int C1, C2, time, h, m, s;
	scanf("%d %d", &C1, &C2);
	time = round((C2 - C1) / CLK_TCK);
	h = time / 60 / 60;
	m = time / 60 % 60;
	s = time % 60;
	printf("%02d:%02d:%02d\n", h, m, s);
	return 0;
}