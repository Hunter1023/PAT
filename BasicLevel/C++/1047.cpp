#include <iostream>
using namespace std; 

int main() {
	int N;
	cin >> N;
	int teamId, id, score, totalScore[1001] = {0};
	while(N--) {
		cin >> teamId >> id >> score;
		totalScore[teamId] += score;
	}
	int max = 1;
	for(int i = 2; i <= 1000; i++) {
		if(totalScore[i] > totalScore[max])
			max = i;
	}
	cout << max << " " << totalScore[max];
	return 0; 
}