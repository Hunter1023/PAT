#include <iostream>
using namespace std;

int main() {
	const string str1[10] = {"ling", "yi", "er", "san", "si",
						"wu", "liu", "qi", "ba", "jiu"}; 
	const string str2[5] = {" Shi", " Bai", " Qian", " Wan", " Yi"};
	string num;
	cin >> num;
	int len = num.length();
	int left = 0, right = len - 1; //分别指向字符串首尾元素
	if(num[0] == '-') { //负数 
		cout << "Fu";
		left++;
	}
	while(left + 4 <= right)
		right -= 4; //将right每次左移4位，直到left与right在同一节(4位或小于4位)
	while(left < len) { 
		int hasZero = 0, hasPrinted = 0;
		while(left <= right) { //循环每次处理数字的一节
			if(left > 0 && num[left] == '0') { //整数不为0 且 当前位是0 
				hasZero = 1;
			} else { //整数为0 或 当前位不是0
				if(hasZero) { //该节中，之前的位是0 
					cout << " ling";
					hasZero = 0;
				}
				if(left > 0) //只要不是首位，后面每一位都要输出空格
					cout << " ";
				cout << str1[num[left] - '0'];
				if(left != right) //不是节中的最后一位 
					cout << str2[right - left - 1]; //输出单位 
				hasPrinted = 1;
			}
			left++; 
		}
		if(hasPrinted && right != len - 1) //当前节有输出，且不是个位 
			cout << str2[(len - 1 - right) / 4 + 2]; //输出节的单位 
		right += 4; 
	} 
	return 0;
}