#include <stdio.h>

int main() {
	int N;
	scanf("%d", &N);
	getchar();
	char answer[4], choose[4]; 
	for (int i = 0; i < N; i++) {
		scanf("%c-%c %c-%c %c-%c %c-%c", &answer[0], &choose[0], 
				&answer[1], &choose[1], &answer[2], &choose[2], &answer[3], &choose[3]);
		for (int j = 0; j < 4; j++) {
			if (choose[j] == 'T') {
				printf("%d", answer[j] - 'A' + 1);
				break;
			}
		}
		getchar();
	}
	printf("\n");
	return 0;
}