#include <iostream>
using namespace std;

int main() {
	int cnt[10];
	for(int i = 0; i < 10; i++)
		cin >> cnt[i];
	for(int i = 1; i < 10; i++) {
		if(cnt[i] != 0) {
			cout << i;
			cnt[i]--;
			break;
		}
	}
	for(int i = 0; i < 10; i++) {
		while(cnt[i]--)
			cout << i;
	}
	return 0;
}