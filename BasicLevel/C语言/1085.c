/* 加权总分是  最后的和取整，之前运算的小数需要保留*/
#include <stdio.h>
#include <string.h>
#include <stdlib.h>
#include <ctype.h>

typedef struct {
	char id[7];//准考证号 
	int grades;//得分 
	char school[7];//学校 
} student;
int cmp1(const void *a, const void *b) {
	student s1 = *(student *)a;
	student s2 = *(student *)b;
	return strcmp(s1.school, s2.school); //根据学校名称排序 
}
typedef struct {
	char name[7];//学校名称 
	int sum; //加权总分 
	int cnt;//考生人数 
} school; 
int cmp2(const void *a, const void *b) {
	school sch1 = *(school *)a;
	school sch2 = *(school *)b;
	if (sch1.sum != sch2.sum) {//加权总分降序 
		return sch2.sum > sch1.sum; 
	} else if (sch1.cnt != sch2.cnt) {//考生人数升序 
		return  sch1.cnt > sch2.cnt;
	} else {//按单位码的升序 
		return strcmp(sch1.name, sch2.name); 
	}
}
int main() {
	int N, cnt_school = 0;//考生人数，单位个数 
	scanf("%d", &N); 
	student stu[N];
	for (int i = 0; i < N; i++) {
		scanf("%s %d %s", stu[i].id, &stu[i].grades, stu[i].school);
		for (int j = 0; j < strlen(stu[i].school); j++) {
			stu[i].school[j] = tolower(stu[i].school[j]);
		}
	}
	qsort(stu, N, sizeof(student), cmp1); 
	school sch[N]; 
	for (int i = 0; i < N; i++) {
		int cnt = 1, sum_B = 0, sum_A = 0, sum_T = 0;//统计某一单位的考生人数
		strcpy(sch[cnt_school].name, stu[i].school);//记录单位名称 
		if (stu[i].id[0] == 'A') {//甲级 
			sum_A +=  stu[i].grades;
		} else if (stu[i].id[0] == 'T') {//顶级 
			sum_T +=  stu[i].grades;
		} else {//乙级 
			sum_B +=  stu[i].grades;
		}
		while (i < N - 1 && !strcmp(stu[i+1].school, stu[i].school)) {//考生同一单位 
			cnt++;
			i++;
			if (stu[i].id[0] == 'A') {//甲级 
				sum_A +=  stu[i].grades;
			} else if (stu[i].id[0] == 'T') {//顶级 
				sum_T +=  stu[i].grades;
			} else {//乙级 
				sum_B +=  stu[i].grades;
			}	
		}
		sch[cnt_school].cnt = cnt;
		sch[cnt_school].sum = (int)((sum_B / 1.5) + sum_A + (sum_T * 1.5));
		cnt_school++;
	}
	printf("%d\n", cnt_school); 
	qsort(sch, cnt_school, sizeof(school), cmp2);
	int rank = 1;//排名
	for (int i = 0; i < cnt_school; i++) {
		int same = 1;//有相同总分的数量 
		printf("%d %s %d %d\n", rank, sch[i].name, sch[i].sum, sch[i].cnt);
		while (i < cnt_school - 1 && sch[i].sum == sch[i+1].sum) {//总分相同 
			i++;
			same++;
			printf("%d %s %d %d\n", rank, sch[i].name, sch[i].sum, sch[i].cnt);
		}
		rank += same;
	}
	return 0;
}