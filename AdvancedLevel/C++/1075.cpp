#include <iostream>
#include <cstring>
#include <algorithm>
using namespace std;

typedef struct {
	int id;
	int score[6]; //每道题的得分情况 
	int hasCompiled = 0; //是否有题目通过了编译 
	int total = 0, solveCnt = 0; //总分，完美解题数 
} user;

bool cmp(user u1, user u2) {
	if(u1.hasCompiled != u2.hasCompiled) {
		return u1.hasCompiled > u2.hasCompiled;
	} else if(u1.total != u2.total) {
		return u1.total > u2.total;
	} else if(u1.solveCnt != u2.solveCnt) {
		return u1.solveCnt > u2.solveCnt;
	} else {
		return u1.id < u2.id;
	}
}

int main() {
	int N, K, M;
	cin >> N >> K >> M;
	int p[K+1];
	for(int i = 1; i <= K; i++)
		cin >> p[i];
	user u[N+1]; //users' id from 1 to N 
	for(int i = 1; i <= N; i++)
		memset(u[i].score, -1, sizeof(u[i].score)); //初始化没提交过答案的题目分数 为 -1 
	int uId, pId, score;
	for(int i = 0; i < M; i++) {
		cin >> uId >> pId >> score;
		u[uId].id = uId;
		if(score != -1) { //有通过编译的提交 
			u[uId].hasCompiled = 1;
		} else { //不能通过编译的题目分数为 0 
			score = 0;
		} 
		if(score > u[uId].score[pId]) {
			u[uId].score[pId] = score;
			if(score == p[pId]) //满分 
				u[uId].solveCnt++;
		}
	}
	for(int i = 1; i <= N; i++) {
		for(int j = 1; j <= K; j++) {
			if(u[i].score[j] > 0)
				u[i].total += u[i].score[j];
		}
	}
	sort(u + 1, u + N + 1, cmp);
	int rank = 1;
	for(int i = 1; i <= N; i++) {
		if(!u[i].hasCompiled)
			break;
		if(i != 1 && u[i].total < u[i-1].total)
			rank = i;
		printf("%d %05d %d", rank, u[i].id, u[i].total);
		for(int j = 1; j <= K; j++) {
			if(u[i].score[j] != -1) {
				printf(" %d", u[i].score[j]);
			} else {
				cout << " -";
			}
		}
		printf("\n");
	}
	return 0;
}