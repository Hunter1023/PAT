#include <iostream>
#include <algorithm>
using namespace std;

typedef struct{
	string id;
	int score, finalRank, locNum, locRank;
} testee;

bool cmp(testee t1, testee t2) { //返回值为true时，t1排在t2之前 
	if(t1.score != t2.score) {
		return t1.score > t2.score;
	} else {
		return t1.id < t2.id;
	}
}

int main() {
	int N, K, cnt = 0;
	testee t[30000];
	cin >> N;
	for(int i = 1; i <= N; i++) {
		cin >> K;
		for(int j = 0; j < K; j++) {
			cin >> t[cnt+j].id >> t[cnt+j].score;
			t[cnt+j].locNum = i;
		}
		cnt += K;
		sort(t + cnt - K, t + cnt, cmp);
		t[cnt - K].locRank = 1;
		for(int j = cnt - K + 1; j < cnt; j++) {
			if(t[j].score != t[j-1].score) {
				t[j].locRank = j - (cnt - K) + 1;
			} else {
				t[j].locRank = t[j-1].locRank;
			}
		}
	}
	sort(t, t + cnt, cmp);
	cout << cnt << endl;
	t[0].finalRank = 1;
	cout << t[0].id;
	printf(" %d %d %d\n", t[0].finalRank, t[0].locNum, t[0].locRank);
	for(int i = 1; i < cnt; i++) {
		if(t[i].score != t[i-1].score) {
			t[i].finalRank = i + 1;
		} else {
			t[i].finalRank = t[i-1].finalRank;
		}
		cout << t[i].id;
		printf(" %d %d %d\n", t[i].finalRank, t[i].locNum, t[i].locRank);
	}
	return 0; 
} 