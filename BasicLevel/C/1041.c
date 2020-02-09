/* 将试机号作为数组下标 */
#include <stdio.h>

typedef struct {
	char id[17];
	int testId;
	int examId;
} student;

int main() {
	int N, M, testId;
	scanf("%d", &N);
	student s[N]; //将数组下标看作试机号 
	for(int i = 0; i < N; i++)
		scanf("%s %d %d", s[i].id, &s[i].testId, &s[i].examId);
	scanf("%d", &M);
	while(M--) {
		scanf("%d", &testId);
		for(int i = 0; i < N; i++) {
			if(s[i].testId == testId) {
				printf("%s %d\n", s[i].id, s[i].examId); 
				break;
			}
		}
	}
	return 0;
}