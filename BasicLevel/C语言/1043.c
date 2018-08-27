/* 待优化 */
#include <stdio.h>
#include <string.h>

typedef struct {
	char c;
	int cnt;
} alpha;
int main() {
	alpha ch[6];//存储P、A、T、e、s、t字符
	ch[0].c = 'P', ch[1].c = 'A', ch[2].c = 'T', ch[3].c = 'e', ch[4].c = 's', ch[5].c = 't';
	char str[10001];
	scanf("%s", str);
	for (int i = 0; i < strlen(str); i++) {
		for (int j = 0; j < 6; j++) {
			if (str[i] == ch[j].c) {
				ch[j].cnt++;
				break;
			}
		}
	}
	int sum;
	do {
		sum = 0;
		for (int i = 0; i < 6; i++) {
			if (ch[i].cnt > 0) {
				printf("%c", ch[i].c);
				ch[i].cnt--;
			}
			sum += ch[i].cnt;
		}
	} while (sum > 0); 
	return 0;
}