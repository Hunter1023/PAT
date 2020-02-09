/*
 * 1. 输入格式正确的前提下，可将字符串形式的日期转为整数，直接判断年龄是否合理
 * 2. 2014/9/6之后 和 1814/9/6之前，为不合理年龄
 * 3. 考虑 全为不合理年龄的情况
 */
#include <stdio.h>
#include <string.h>

int main() {
	int N;//人数 
	scanf("%d", &N); 
	char name[6], minName[6], maxName[6];
	int year, month, day, cnt = 0; //年月日，有效生日的个数 
	int maxBDay = 20140907, minBDay = 18140905; //不合理年龄的临界点
	for(int i = 0; i < N; i++) {
		scanf("%s %d/%d/%d", name, &year, &month, &day);
		int age = year*10000 + month*100 + day;
		if(age < 20140907 && age > 18140905) { //如果是合理年龄 
			cnt++;
			if(age < maxBDay) { //最年长 
				maxBDay = age;
				strcpy(maxName, name);
			} 
			if(age > minBDay) { //最年幼 
				minBDay = age;
				strcpy(minName, name); 
			}
		}
	} 
	printf("%d", cnt);
	if(cnt != 0) //存在有效生日
		printf(" %s %s", maxName, minName);
	return 0;
}