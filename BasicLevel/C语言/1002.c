#include <stdio.h>
#include <string.h>

int main() {
	int sum = 0; //获取输入的数字之和 
	char strsum[4]; //输入的数字长度 < 1000,数字和必然小于9000，大小为4的字符串即能存放 
	char pinyin[10][5] = {"ling", "yi", "er", "san", "si", "wu", "liu", "qi", "ba", "jiu"};
	
	char num; //读取数字 
	while ((num = getchar()) != '\n') {//数字求和 
		sum += (num-'0');
	}
	sprintf(strsum, "%d", sum); //将任意类型数据转换成字符串  
	
	//输出
	for (int i = 0; i < strlen(strsum); i++) {
		if(i != 0) {// 如果不是第一个数字，先添加空格
			printf(" ");
		}
		printf("%s", pinyin[strsum[i]-'0']); //根据数组下标，获取对应拼音
	}
	return 0;
} 