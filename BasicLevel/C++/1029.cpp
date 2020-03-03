#include <iostream>
using namespace std;

int main() {
	string str1, str2;
	cin >> str1 >> str2;
	int len1 = str1.length();
	int key[128] = {0}, j = 0;
	for(int i = 0; i < len1; i++) {
		if(str1[i] == str2[j]) {
			j++;
		} else { //有坏键
			char c = toupper(str1[i]);
			if(key[c] == 0) { //第一次发现坏键 
				cout << c;
				key[c] = 1;
			} 
		}	
	}
	return 0;
}