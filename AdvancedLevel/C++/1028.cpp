#include <iostream>
#include <algorithm>
using namespace std;

typedef struct {
	int id;
	string name;
	int grades;
} student;

bool cmp1(student s1, student s2) {
	return s1.id < s2.id;
} 

bool cmp2(student s1, student s2) {
	if(s1.name != s2.name) {
		return s1.name < s2.name;
	} else {
		return s1.id < s2.id;
	}
}

bool cmp3(student s1, student s2) {
	if(s1.grades != s2.grades) {
		return s1.grades < s2.grades;
	} else {
		return s1.id < s2.id;
	}
}

int main() {
	int N, C;
	cin >> N >> C;
	student s[N];
	for(int i = 0; i < N; i++)
		cin >> s[i].id >> s[i].name >> s[i].grades;
	if(C == 1) { //id升序 
		sort(s, s + N, cmp1);
	} else if(C == 2) {
		sort(s, s + N, cmp2);
	} else {
		sort(s, s + N, cmp3);
	}
	for(int i = 0; i < N; i++) {
		printf("%06d ", s[i].id);
		cout << s[i].name << " " << s[i].grades << endl;
	} 
	return 0;
} 