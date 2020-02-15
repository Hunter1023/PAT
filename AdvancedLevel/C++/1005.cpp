#include <iostream>
using namespace std;

int main() {
	const string str[10] = {"zero", "one", "two", "three", "four",
							"five", "six", "seven", "eight", "nine"};
	string N;
	cin >> N;
	int sum = 0, len = N.length();
	for(int i = 0; i < len; i++)
		sum += N[i] - '0';
	N = to_string(sum);
	len = N.length();
	cout << str[N[0] - '0'];
	for(int i = 1; i < len; i++)
			cout << " " << str[N[i] - '0'];
	return 0;
}