#include <stdio.h>
#include <ctype.h>

int main() {
	int sum = 0;
	char c;
	while((c = getchar()) != '\n') {
		if (isalpha(c)) {
			c = tolower(c);
			sum += c - 'a' + 1;
		}
	}
	int cnt_0 = 0, cnt_1 = 0;
	while (sum != 0) {
		if (sum % 2 == 0) {
			cnt_0++;
		} else {
			cnt_1++;
		}
		sum /= 2;
	}
	printf("%d %d\n", cnt_0, cnt_1);
	return 0;
}