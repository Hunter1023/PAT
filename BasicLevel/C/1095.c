#include <stdio.h>
#include <stdlib.h>
#include <string.h>

typedef struct {
    char str[14]; // 准考证号
	char level; //考试级别
	int room; //考场编号
	int date; //考试日期
	int id; //考生编号
	int scores; // 分数
} Student;

int cmp(const void *a, const void *b) {
    Student s1 = *(Student*)a;
    Student s2 = *(Student*)b;
    if(s1.scores != s2.scores) { //按分数降序
        return s2.scores - s1.scores;
	} else { //按字典顺序递增输出
		return strcmp(s1.str, s2.str);
	}
}

int main() {
    int N, M, type, NAflag; //考生人数、统计要求的个数、类型，查询结果是否为空
    scanf("%d %d", &N, &M);
	Student s[N];
    for (int i = 0; i < N; i++) {
        scanf("%s %d", s[i].str, &s[i].scores);
        sscanf(s[i].str, "%c%3d%6d%3d", &s[i].level,
                &s[i].room, &s[i].date, &s[i].id); //从字符串读取格式化输入
    }
    for (int i = 0; i < M; i++) {
        NAflag = 1; //初始化查询结果为空
        scanf("%d ", &type);
		printf("Case %d: %d ", i + 1, type);
        if (type == 1) { //按分数降序 输出指定级别考生的成绩
            char cmd;
            scanf("%c", &cmd); //读入指令
            printf("%c\n", cmd);
			qsort(s, N, sizeof(Student), cmp);
            for(int j = 0; j < N; j++) {
                if(s[j].level == cmd) {
                    NAflag = 0; //有查询结果
                    printf("%s %d\n", s[j].str, s[j].scores);//字符串长度需>13，否则输出错误
                }
			} 
		} else if (type == 2) {//统计 指定考场 的考生人数和总分统计
			int room, sum = 0, cnt = 0;
			scanf("%d", &room); //读入考场
			printf("%d\n", room);
			for (int j = 0; j < N; j++) {
				if(s[j].room == room) {
					NAflag = 0;
					cnt++;
					sum += s[j].scores;
				}
			}
			if(!NAflag) {
				printf("%d %d\n", cnt, sum);
			}
		} else if (type == 3) { //按人数降序 输出 指定日期 分考场的考生人数
			int date, max = 0, rooms[1000] = {0};
			scanf("%d", &date); //读入日期
			printf("%06d\n", date);
			for(int j = 0; j < N; j++) {
				if(s[j].date == date) {
					NAflag = 0;
					rooms[s[j].room]++;
					if(max < rooms[s[j].room]) {
						max = rooms[s[j].room];
					}
				}
			}
			if(!NAflag) {
				for(int c = max; c > 0; c--) {
					for(int r = 101; r < 1000; r++) {
						if(rooms[r] == c) {
							printf("%d %d\n", r, c);
						}
					}
				}
			}
		}
		if (NAflag) {
			printf("NA\n");
		}
    }
    return 0;
}