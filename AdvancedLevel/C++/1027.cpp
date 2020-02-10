#include <cstdio>

int main() {
	const char c[14] = "0123456789ABC";
    int color;
    printf("#");
    for(int i = 0; i < 3; i++) {
    	scanf("%d", &color);
    	printf("%c%c", c[color / 13], c[color % 13]);
	}
    return 0;
}