#include <iostream>
using namespace std;

int main() {
	int cnt[128] = {0};
	string str1, str2;
	cin >> str1 >> str2;
	int len1 = str1.size(), len2 = str2.size();
	for(int i = 0; i < len1; i++)
		cnt[str1[i]]++;
	int extra = len1 - len2, missing = 0;
	for(int i = 0; i < len2; i++) {
		cnt[str2[i]]--;
		if(cnt[str2[i]] < 0)
			missing++;
	}
	if(missing != 0) { //不满足需要
		cout << "No " << missing << endl;
	} else {
		cout << "Yes " << extra << endl;
	}
	return 0;
} 