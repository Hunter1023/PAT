#include <iostream>
#include <algorithm> 
using namespace std;

typedef struct{
	int id, grades[4];
} student;
int index, Rank[1000000][4] = {0};

bool cmp(student s1, student s2) { //返回值为true时，s1在前 
	return s1.grades[index] > s2.grades[index]; //降序 
}

int main() {
	int N, M;
	cin >> N >> M;
	student s[N];
	for(int i = 0; i < N; i++) {
		cin >> s[i].id >> s[i].grades[1] >> s[i].grades[2] >> s[i].grades[3];
		s[i].grades[0] = (s[i].grades[1] + s[i].grades[2] + s[i].grades[3]) / 3.0 + 0.5; //四舍五入 
	}
	for(index = 0; index < 4; index++) {
		sort(s, s + N, cmp);
		Rank[s[0].id][index] = 1; //记录当前科目的第1名 
		for(int i = 1; i < N; i++) { //对于剩下的考生 
			if(s[i].grades[index] == s[i-1].grades[index]) {//与前一位考生分数相同 
				Rank[s[i].id][index] = Rank[s[i-1].id][index];
			} else {
				Rank[s[i].id][index] = i + 1;
			}
		}
	}
	int id;
	char str[5] = "ACME";
	while(M--) {
		cin >> id;
		if(Rank[id][0] != 0) { //存在该考生
			index = 0; //排名最高的科目 
			for(int i = 1; i < 4; i++) {
				if(Rank[id][i] < Rank[id][index])
					index = i;
			} 
			printf("%d %c\n", Rank[id][index], str[index]);
		} else {
			printf("N/A\n");
		}
	}
	return 0;
}