#include <iostream>
#include <algorithm>
using namespace std;

typedef struct {
	int id, vGrade, tGrade, flag;
} man;

bool cmp(man a, man b) { //返回值为true时，a被排在b之前
	if(a.flag != b.flag) { //按类别
		return a.flag < b.flag; //升序 
	} else if(a.tGrade + a.vGrade != b.tGrade + b.vGrade) { //按总分 
		return a.tGrade + a.vGrade > b.tGrade + b.vGrade; //降序 
	} else if(a.vGrade != b.vGrade) { //按德分 
		return  a.vGrade > b.vGrade; //降序 
	} else { //按准考证号 
		return a.id < b.id; //升序 
	} 
}

int main() {
	int N, L, H;
	cin >> N >> L >> H;
	int cnt = 0; //及格人数 
	man m[N];
	for(int i = 0; i < N; i++) {
		cin >> m[i].id >> m[i].vGrade >> m[i].tGrade;
		if(m[i].vGrade >= L && m[i].tGrade >= L) {
			cnt++;
			if(m[i].vGrade >= H && m[i].tGrade >= H) { //sage
				m[i].flag = 1;
			} else if(m[i].vGrade >= H) { //noble
				m[i].flag = 2;
			} else if(m[i].vGrade >= m[i].tGrade) { //fool
				m[i].flag = 3;
			} else { //small
				m[i].flag = 4;
			}
		} else { //不及格
			m[i].flag = 5;
		}
	}
	cout << cnt << endl;
	sort(m, m + N, cmp);
	for(int i = 0; i < cnt; i++)
		printf("%08d %d %d\n", m[i].id, m[i].vGrade, m[i].tGrade);
	return 0;
}