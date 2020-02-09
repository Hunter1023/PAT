/*
 * 1. 输入格式正确的前提下，可直接按字符串形式比较，判断年龄是否合理
 * 2. 2014/9/6之后 和 1814/9/6之前，为不合理年龄
 * 3. 考虑 全为不合理年龄的情况
 */
#include <iostream>
using namespace std;

int main() {
	int N, cnt = 0;//人数，合理人数
	cin >> N;
	string maxLimit = "1814/09/05", minLimit = "2014/09/07"; //不合理年龄的临界点
	string name, bDay, minName, maxName, maxBDay = minLimit, minBDay = maxLimit;
	while(N--) {
		cin >> name >> bDay;
		if(bDay > maxLimit && bDay < minLimit) {//如果是合理年龄 
			cnt++;
			if(bDay < maxBDay ) {//最年长 
				maxBDay = bDay;
				maxName = name;
			} 
			if(bDay > minBDay) {//最年幼 
				minBDay = bDay;
				minName = name;
			}
		}
	} 
	cout << cnt;
	if(cnt != 0) //存在有效生日
		cout  << " " << maxName << " " << minName;
	return 0;
}