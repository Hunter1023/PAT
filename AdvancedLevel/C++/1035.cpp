#include <iostream>
using namespace std;

int main() {
	int N, cnt = 0;
	cin >> N;
	string str1[2], str2[N][2];
	for(int i = 0; i < N; i++) {
		cin >> str1[0] >> str1[1];
		int isConf = 0, len = str1[1].length();
		for(int j = 0; j < len; j++) {
			if(str1[1][j] == '1') {
				isConf = 1;
				str1[1][j] = '@';
			} else if(str1[1][j] == '0') {
				isConf = 1;
				str1[1][j] = '%';
			} else if(str1[1][j] == 'l') {
				isConf = 1;
				str1[1][j] = 'L';
			} else if(str1[1][j] == 'O') {
				isConf = 1;
				str1[1][j] = 'o';
			}
		}
		if(isConf) {
			str2[cnt][0] = str1[0];
			str2[cnt][1] = str1[1];
			cnt++;
		}
	}
	if(cnt != 0) {
		cout << cnt << endl;
		for(int i = 0; i < cnt; i++)
			cout << str2[i][0] << " " << str2[i][1] << endl;
	} else if(N == 1) {
		cout << "There is 1 account and no account is modified";
	} else {
		cout << "There are " << N << " accounts and no account is modified";	
	}
	return 0;
}