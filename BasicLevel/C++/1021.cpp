#include <cstdio>
#include <cstring>

int main() {
	char N[1001];
	scanf("%s", &N);
	int len = strlen(N), cnt[10] = {0};
	for(int i = 0; i < len; i++)
		cnt[N[i] - '0']++;
	for(int i = 0; i < 10; i++) {
		if(cnt[i] != 0)
			printf("%d:%d\n", i, cnt[i]);
	}
	return 0; 
}