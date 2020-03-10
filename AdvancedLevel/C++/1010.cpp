#include <iostream>
#include <algorithm>
using namespace std;

long long getNum(string str, int length, long long radix) {
	long long num = 0;
	int tmp;
	for(int i = 0; i < length; i++) {
		if(isalpha(str[i])) {
			tmp = str[i] - 'a' + 10; 
		} else {
			tmp = str[i] - '0';
		}
		num = num * radix + tmp;
	}
	return num;
}

long long getRadix(string str, long long num) {
	string::iterator it = max_element(str.begin(), str.end()); //max_element 是 algorithm 下的函数，返回对应的迭代器 
	long long low = (isdigit(*it) ? *it - '0' : *it - 'a' + 10) + 1; //基数的下界是 未转换数的最大字符对应值 + 1 
	long long high =  max(num + 1, low); //上界是 已知数+1 和 下界 中的较大值，能确保不会出现多个解 
	long long mid, tmp;
	while(low <= high) {
		mid = (low + high) / 2;
		tmp = getNum(str, str.size(), mid);
		if(tmp > num || tmp < 0) { //基数过大时会发生上溢，存储结果为负数 
			high = mid - 1; 
		} else if(tmp < num) { //基数需要增大 
			low = mid + 1;
		} else { //必然唯一解 
			return mid;
		} 
	} 
	return -1;
}

int main() {
	string str[3];
	int tag;
	long long radix, num;
	cin >> str[1] >> str[2] >> tag >> radix;
	num = getNum(str[tag], str[tag].size(), radix);
	tag = tag == 1 ? 2 : 1;
	radix = getRadix(str[tag], num);
	if(radix == -1) {
		cout << "Impossible" << endl;
	} else {
		cout << radix << endl;
	}
	return 0;
}