#include <stdio.h>
#include <string.h>

int main() {
	char num[101];//输入的数字 < 10^{100}，即数字的位数 < 101
	scanf("%s", num);
	int sum = 0, len = strlen(num); //各位数字之和(易知<= 900)；数字的位数
	for (int i = 0; i < len; i++) {
		sum += num[i] - '0';
	}
	char pinyin[10][5] = {"ling", "yi", "er", "san", "si", "wu", "liu", "qi", "ba", "jiu"};
	if (sum / 100 > 0) {//和 >= 100 输出百位数 
		printf("%s ", pinyin[sum / 100]);
	}
	if (sum / 10 > 0) {//和 >= 10 输出十位数 
		printf("%s ", pinyin[sum / 10 % 10]);//注意百位数的干扰 
	}
	printf("%s\n", pinyin[sum % 10]);//输出个位数
	return 0;
} 