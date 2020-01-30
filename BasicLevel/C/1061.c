#include <stdio.h>

typedef struct {
	int score;//分值 
	int correct;//答案 
} question; 
int main(){
	int N, M;//学生人数，判断题数量 
	scanf("%d %d", &N, &M);
	question q[M];
	for (int i = 0; i < M; i++) {
		scanf("%d", &q[i].score);//读取分值 
	}
	for (int i = 0; i < M; i++) {
		scanf("%d", &q[i].correct);//读取答案 
	}
	for (int i = 0; i < N; i++) {
		int sum = 0;
		for (int j = 0; j < M; j++) {
			int answer;
			scanf("%d", &answer);
			if (answer == q[j].correct) {
				sum += q[j].score;
			}
		}
		printf("%d\n", sum);
	}
	return 0;
}