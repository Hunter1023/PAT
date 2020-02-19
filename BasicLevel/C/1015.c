/* 排序：按 学生分类升序；总分降序；德分降序；准考证号升序 */
#include <stdio.h>
#include <stdlib.h>

typedef struct {
	int id, de, cai, flag;
} man;

int cmp(const void *a, const void *b) { //返回值<0, a被排在b之前；返回值>0，a被排在b之后
	man m1 = *(man *)a;
	man m2 = *(man *)b;
	if(m1.flag != m2.flag) { //类别升序
		return m1.flag - m2.flag
	} else if((m1.de + m1.cai) != (m2.de + m2.cai)) {//总分降序 
		return (m2.de + m2.cai) - (m1.de + m1.cai);  
	} else if( m1.de != m2.de) { //德分降序 
		return m2.de - m1.de;
	} else{ //准考证号升序
		return m1.id - m2.id; 
	}
}
int main() {
	int N, L, H; 
	scanf("%d %d %d", &N, &L, &H);
	int cnt = 0; //及格人数
	man m[N];
	for(int i = 0; i < N; i++) {
		scanf("%d %d %d", &m[i].id, &m[i].de, &m[i].cai);
		if(m[i].de >= L && m[i].cai >= L) { //及格
			cnt++;
			if(m[i].de >= H && m[i].cai >= H) { //才德全尽 
				m[i].flag = 1;
			} else if(m[i].de >= H) { //德胜才 
				m[i].flag = 2;
			} else if(m[i].de >= m[i].cai) { //才德兼亡尚有德胜才
				m[i].flag = 3;
			} else {
				m[i].flag = 4;
			}
		} else { //不及格
			m[i].flag = 5;
		}
	}
	printf("%d\n", cnt);
	qsort(m, N, sizeof(man), cmp);
	for(int i = 0; i < cnt; i++)
		printf("%08d %d %d\n", m[i].id, m[i].de, m[i].cai);
	return 0; 
}