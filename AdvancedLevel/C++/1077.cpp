#include <iostream>
#include <algorithm>
using namespace std;

int main() {
	int N, minLen = 256;
	scanf("%d\n", &N); //必须读取换行符 
	string str[N];
	for(int i = 0; i < N; i++) {
		getline(cin, str[i]);
		reverse(str[i].begin(), str[i].end());
		if(str[i].length() < minLen)
			minLen = str[i].length();
	}
	int index = -1, flag = 1;
	for(int i = 0; i < minLen; i++) {
		for(int j = 1; j < N; j++) {
			if(str[0][i] != str[j][i]) {
				flag = 0;
				break;
			}
		}
		if(!flag) {
			break;
		} else {
			index++;
		}
	}
	if(index >= 0) {
		for(int i = index; i >= 0; i--)
			cout << str[0][i];
	} else {
		cout << "nai" << endl;
	}
	return 0;
}