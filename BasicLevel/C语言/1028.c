/*
 * 1. 把src的字符串复制给dst  char* strcpy(char *restrict dst, const char *restrict src);
 * 2. 考虑全为不合理年龄的情况
 * 3. 输入格式正确的前提下，合理年龄的判断可以将字符串形式的日期转为整数，直接比较
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
		if (age < 20140907 && age > 18140905) {//如果是合理年龄 
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
	} else {
		printf("0\n");
	}
	return 0;
}