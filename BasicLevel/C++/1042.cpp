#include <iostream>
using namespace std;

int main() {
	int cnt[26] = {0};
	string str;
	getline(cin, str);
	int len = str.size();
	for(int i = 0; i < len; i++) {
		if(isalpha(str[i]))
			cnt[tolower(str[i])-'a']++;
	}
	int max = 0;
	for(int i = 1; i < 26; i++) {
		if(cnt[i] > cnt[max])
			max = i;
	}
	cout << static_cast<char>('a' + max) << ' ' << cnt[max] << endl; 
	return 0;
}