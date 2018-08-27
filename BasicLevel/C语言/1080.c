/*
 * 待优化
 * 1. 该题考察了时间复杂度
 * 2. 利用 bsearch() 对学号二分查找，降低时间复杂度
 * 3. 待学习C语言下hashmap的使用：[解题参考](https://blog.csdn.net/futangxiang4793/article/details/79377683)
 */
#include <stdio.h>
#include <math.h>
#include <stdlib.h>
#include <string.h>

typedef struct {
	char id[21];//学号
	int p_grades;//编程成绩
	int mid_grades;//期中成绩 
	int final_grades;//期末成绩 
	int grades;//总成绩 
} student;
int cmp1(const void *a, const void *b) {
	student s1 = *(student *)a;
	student s2 = *(student *)b;
	return strcmp(s1.id, s2.id);//学号递增 
};
int cmp2(const void *a, const void *b) {
	student s1 = *(student *)a;
	student s2 = *(student *)b;
	if (s2.grades != s1.grades) { //总分不同 
		return s2.grades > s1.grades;//总分递减 
	} 
	return strcmp(s1.id, s2.id);//总分相同 学号递增 
};
int cmp_bsearch(const void *id, const void *stu) {//折半查找的比较函数 
	student s1 = *(student *)stu;
	char *c = (char *)id;
	return strcmp(c, s1.id);
}
int main() {
	int P, M, N;//做了在线编程作业的学生数，参加其中考试的学生数，参加期末考试的学生数 
	scanf("%d %d %d", &P, &M, &N);
	student stu[P];//只有编程成绩达标才能获得证书，即最多P人获得证书 
	for (int i = 0; i < P; i++) {
		stu[i].final_grades = -1;
		stu[i].mid_grades = -1;
	}
	int cnt = 0, grades_p, grades_mid, grades_final; 
	char id[21];
	for (int i = 0; i < P; i++) {//读入编程成绩
		scanf("%s %d", id, &grades_p);
		if (grades_p >= 200) {//编程分数>=200 
			strcpy(stu[cnt].id, id);
			stu[cnt].p_grades = grades_p;
			cnt++;
		}
	}
	qsort(stu, cnt, sizeof(student), cmp1);
	student *s;
	for (int i = 0; i < M; i++) {//读入期中成绩 
		scanf("%s %d", id, &grades_mid);
		s = (student *)bsearch(id, stu, cnt, sizeof(student), cmp_bsearch);//折半查找 
		if (s != NULL) {
			s->mid_grades = grades_mid;
		}
	}
	for (int i = 0; i < N; i++) {//读入期末成绩 
		scanf("%s %d", id, &grades_final);
		s = (student *)bsearch(id, stu, cnt, sizeof(student), cmp_bsearch);//折半查找 
		if (s != NULL) {
			s->final_grades = grades_final;
		}
	}
	for (int i = 0; i < cnt; i++) {//编程成绩达标人数为cnt 
		if (stu[i].mid_grades > stu[i].final_grades) {
			stu[i].grades = round(0.4 * stu[i].mid_grades + 0.6 * stu[i].final_grades);//四舍五入 
		} else {
			stu[i].grades = stu[i].final_grades;
		}
	} 
	qsort(stu, cnt, sizeof(student), cmp2);
	for (int i = 0; i < cnt; i++) {
		if (stu[i].grades < 60) {
			break;
		}
		printf("%s %d %d %d %d\n", stu[i].id, stu[i].p_grades, 
			stu[i].mid_grades, stu[i].final_grades, stu[i].grades);
	}
	return 0;
}