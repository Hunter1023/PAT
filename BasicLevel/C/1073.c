/* 
 * （该题为 1058. 选择题 的基础上，增加了 选择部分正确选项&没选错误选项，则得到50%分数的判断）
 */
#include <stdio.h>
#include <stdlib.h>

typedef struct {
	int score;//满分值 
	int cnt;//2 <= 选项个数 <= 5
	int right_cnt;//正确选项的个数
	int opt[5];//下标代表选项 
} question; 
int main() {
	int N, M;//学学生人数、多选题的个数
	scanf("%d %d", &N, &M);
	question q[M];
	for (int i = 0; i < M; i++) {
		for (int j = 0; j < 5; j++) {
			q[i].opt[j] = 0;
		}
	}
	for (int i = 0; i < M; i++) {//给出多选题
		scanf("%d %d %d", &q[i].score, &q[i].cnt, &q[i].right_cnt);
		char c; 
		for (int j = 0; j < q[i].right_cnt; j++) {
			scanf(" %c", &c);
			q[i].opt[c-'a']++;//记录答案 
		}
	}
	int error[M][5], max_error = 0;
	for (int i = 0; i < M; i++) {
		for (int j = 0; j < 5; j++) {
			error[i][j] = 0;//错误次数 
		}
	}
	for (int i = 0; i < N; i++) { //学生答题情况
		getchar();
		double grades = 0.0;
		for (int j = 0; j < M; j++) { //每一道题的答案 
			int opt_cnt, isRight = 1, isAllRight = 1;//选择的数量, 选项是否正确 
			char c; 
			int opt_stu[5] = {0};
			scanf("(%d", &opt_cnt);
			for (int k = 0; k < opt_cnt; k++) {
				scanf(" %c", &c);
				opt_stu[c-'a'] = 1;//选择了该选项 
			}
			for (int k = 0; k < 5; k++) {
				if(q[j].opt[k] == 1 && opt_stu[k] == 0) {//答案有， 没选该答案 
					isAllRight = 0;
					error[j][k]++;
				} else if (q[j].opt[k] == 0 && opt_stu[k] == 1) {//答案没有，选了该答案，不得分 
					isRight = 0;
					error[j][k]++;
				}
				if (max_error < error[j][k]) {
					max_error = error[j][k];
				}
			} 
			scanf(")");
			if (j != M - 1) {
				scanf(" ");
			}
			if (isRight) {//选项都正确 
				if (!isAllRight) {//选择的数量 少于正确答案
					grades += q[j].score / 2.0;
				} else {//选择的数量 等于 正确答案
					grades += q[j].score;
				}
			}
		}
		printf("%.1f\n", grades);
	}
	if (max_error == 0) {
		printf("Too simple\n");
	} else {
		for (int i = 0; i < M; i++) {
			for (int j = 0; j < 5; j++) {
				if (error[i][j] == max_error) {
					printf("%d %d-%c\n", error[i][j], i+1, 'a'+j);
				}
			}
		}
	}
	return 0;
}