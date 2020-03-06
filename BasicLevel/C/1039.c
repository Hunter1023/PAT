#include <stdio.h>
#include <string.h>

int main() {
	char str1[1001], str2[1001];
	int cnt[128] = {0};
	scanf("%s\n%s", str1, str2);
	int len1 = strlen(str1), len2 = strlen(str2);
	for(int i = 0; i < len1; i++)
		cnt[str1[i]]++;
	int extra = len1 - len2, missing = 0;
	for(int i = 0; i < len2; i++) {
		cnt[str2[i]]--;
		if(cnt[str2[i]] < 0)
			missing++;
	}
    if(missing != 0) { //不满足需要
		printf("No %d\n", missing);
	} else {
		printf("Yes %d\n", extra); 
	}
	return 0;
}