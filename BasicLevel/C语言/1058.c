/* 能否进一步优化 */
#include <stdio.h>
#include <string.h>
#include <stdlib.h>
#include <ctype.h>

typedef struct {//题目 
	int score;//分值  
	int right_cnt;//正确选项个数
	char right[6];//所有正确选项 
	int wrong;//错误的次数
} question; 
int main(){
	int N, M, max_error = 0;//学生人数，多选题个数，最多错误次数 
	scanf("%d %d", &N, &M);
	question q[M+1];
	for(int i = 1; i < M + 1; i++) {//读入多选题 
		int cnt, j = 0;//选项个数（无用） 
		scanf("%d %d %d", &q[i].score, &cnt, &q[i].right_cnt);
		q[i].wrong = 0;//初始化错误的次数
		char c;
		while ((c = getchar()) != '\n') {
			if (isalpha(c)) {
				q[i].right[j] = c;
				j++;
			}
		}
		q[i].right[j] = '\0';
	}
	for (int i = 0; i < N; i++) {//读入解答 
		int grades = 0, j;//学生得分
		for (j = 1; j < M + 1; j++) {
			int cnt;//选项的个数 
			scanf("(%d", &cnt);
			int k = 0;
			char c, choose[6];
			while ((c = getchar()) != ')') {
				if (isalpha(c)) {
					choose[k] = c;
					k++;
				}
			}
			choose[k] = '\0';
			if (cnt == q[j].right_cnt && strcmp(choose, q[j].right) == 0) {//如果正确，加上分数
				grades += q[j].score;
			} else {//错误则统计错误次数 
				q[j].wrong++;
			}
			if (max_error < q[j].wrong) {
				max_error = q[j].wrong;
			}
			getchar();
		}
		printf("%d\n", grades);
	}
	if (max_error == 0) {//没有错题 
		printf("Too simple");
	} else {
		printf("%d", max_error);
		for (int i = 1; i < M + 1; i++) {
			if (q[i].wrong == max_error) {
				printf(" %d", i);
			}
		}
	}
	printf("\n");
	return 0;
}