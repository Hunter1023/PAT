/*
 * 1. 输入格式正确的前提下，可以将字符串形式的日期转为整数，直接判断年龄是否合理
 * 2. 2014/9/6之后 和 1814/9/6之前，为不合理年龄
 * 3. 考虑 全为不合理年龄的情况
 */
#include <stdio.h>
#include <string.h>

int main() {
	int N;//人数 
	scanf("%d", &N); 
	char name[6], young_name[6], old_name[6];
	int year, month, day, cnt = 0;//年月日，有效生日的个数 
	int maxAge = 2014*10000 + 9*100 + 7;//不合理年龄的临界点 
	int minAge = 1814*10000 + 9*100 + 5;
	for (int i = 0; i < N; i++) {
		scanf("%s %d/%d/%d", name, &year, &month, &day);
		int age = year*10000 + month*100 + day;
		if (age < maxAge && age > minAge) {//如果是合理年龄 
			cnt++;
			if (age < maxAge ) {//最年长 
				maxAge = age;
				strcpy(old_name, name);
			} 
			if (age > minAge) {//最年幼 
				minAge = age;
				strcpy(young_name, name); 
			}
		}
	} 
	if (cnt != 0) {
		printf("%d %s %s\n", cnt, old_name, young_name);
	} else {//全为无效生日
		printf("0\n");
	}
	return 0;
}