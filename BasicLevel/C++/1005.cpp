#include <iostream>
#include <cstring>
using namespace std;

int main() {
	int K, isKey[101], num;
	memset(isKey, -1, sizeof(isKey));
	cin >> K;
	while(K--) {
		cin >> num;
		if(isKey[num] == -1) {//还未判断过 
			isKey[num] = 1; //关键数
			while(num != 1) {
				if(num % 2 == 1) //奇数 
					num = 3 * num + 1;
				num /= 2;
				if(num <= 100) //奇数可能会超过100 
					isKey[num] = 0;	//非关键数
			}
		}
	}
	int isFirst = 1;
	for(int i = 100; i > 1; i--) {
		if(isKey[i] == 1) {
			if(!isFirst)
				cout << ' ';
			cout << i;
			isFirst = 0;
		}
	}
	return 0;
} 