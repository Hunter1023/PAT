#include <iostream>
using namespace std;

int main() {
	int N, K, cnt[101] = {0}, score;
	cin >> N;
	while(N--) {
		cin >> score;
		cnt[score]++;
	}
	cin >> K;
	for(int i = 0; i < K; i++) {
		if(i != 0)
			cout << ' ';
		cin >> score;
		cout << cnt[score];
	}
	return 0;
} 