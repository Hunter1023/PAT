#include <iostream>
#include <algorithm>
using namespace std;

typedef struct {
	int id, de, cai, flag;
} man;

bool cmp(man a, man b) { //返回值为true时，a被排在b之前
	if(a.flag != b.flag) { //按类别
		return a.flag < b.flag; //升序 
	} else if(a.cai + a.de != b.cai + b.de) { //按总分 
		return a.cai + a.de > b.cai + b.de; //降序 
	} else if(a.de != b.de) { //按德分 
		return  a.de > b.de; //降序 
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
		cin >> m[i].id >> m[i].de >> m[i].cai;
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
	cout << cnt << endl;
	sort(m, m + N, cmp);
	for(int i = 0; i < cnt; i++)
		printf("%08d %d %d\n", m[i].id, m[i].de, m[i].cai);
	return 0;
}