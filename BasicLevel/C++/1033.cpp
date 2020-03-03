#include <iostream>
using namespace std;

int main() {
	string str1, str2;
	getline(cin, str1);
	getline(cin, str2);
	int key[128] = {0}, len1 = str1.length();
	for(int i = 0; i < len1; i++) //标记失效键 
		key[str1[i]] = 1;
	int len2 = str2.length();
	for(int i = 0; i < len2; i++) {
		if(key[toupper(str2[i])]) { //坏键 
			continue;
		} else if(key['+'] && isupper(str2[i])) { //上档键坏 且 为大写字母 
			continue; 
		}
		cout << str2[i];
	} 
	cout << endl; 
	return 0;
}