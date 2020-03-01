#include <iostream>
#include <algorithm>
using namespace std;

typedef struct {
	string name;
	int age, worth;
} person;

bool cmp(person p1, person p2) {
	if(p1.worth != p2.worth) {
		return p1.worth > p2.worth;
	} else if(p1.age != p2.age) {
		return p1.age < p2.age;
	} else {
		return p1.name < p2.name;
	}
}

int main() {
	int N, K;
	cin >> N >> K;
	person p[N];
	for(int i = 0; i < N; i++)
		cin >> p[i].name >> p[i].age >> p[i].worth;
	sort(p, p + N, cmp);
	int ageCnt[201] = {0}, validN = 0; //年龄范围是 (0,200]，记录每个年龄的富豪人数 
	person validP[N]; //最多输出100位富豪，多余的需要筛去，避免超时
	for(int i = 0; i < N; i++) {
		if(ageCnt[p[i].age] < 100) { //该年龄的富豪人数未到100 
			ageCnt[p[i].age]++; 
			validP[validN] = p[i];
			validN++;
		}
	}
	int M, Amin, Amax;
	for(int i = 1; i <= K; i++) {
		cin >> M >> Amin >> Amax;
		cout << "Case #" << i << ":" << endl;
		int cnt = 0;
		for(int j = 0; cnt < M && j < validN; j++) {
			if(validP[j].age >= Amin && validP[j].age <= Amax) {
				cout << validP[j].name << " " << validP[j].age << " " << validP[j].worth << endl;
				cnt++; 
			}
		}
		if(cnt == 0)
			cout << "None" << endl;
	} 
	return 0;
} 