#include <cstdio>

int main() {
    int N, b, index = 0, a[31];
    scanf("%d %d", &N, &b);
    do {
    	a[index++] = N % b;
    	N /= b;
	} while(N != 0);
	index--;
	int isP = 1;
    for(int i = 0; i <= index / 2; i++) {
    	if(a[i] != a[index - i]) {
    		printf("No\n");
    		isP = 0;
    		break;
		}
	}
	if(isP)
    	printf("Yes\n");
    for(int j = index; j >= 0; j--) {
		if(j != index)
			printf(" ");
		printf("%d", a[j]);
	}
    return 0;
}