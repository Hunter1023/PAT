#include <iostream>
using namespace std;

int main() {
	int a, b;
	cin >> a >> b;
	string sum = to_string(a + b);
	int len = sum.length();
	for(int i = 0; i < len; i++) {
		cout << sum[i];
		if(sum[i] == '-')
			continue;
		if((i + 1) % 3 == len % 3 && i != len - 1)
			cout << ",";
	}
	return 0;
}