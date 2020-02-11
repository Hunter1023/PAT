#include <stdio.h>

int main() {
	int num; //正整数n < 1000 
	scanf("%d", &num);
	for(int i = 0; i < num / 100; i++) //输出百位 
		printf("B");
	for(int i = 0; i < num / 10 % 10; i++) //输出十位 
		printf("S");
	for(int i = 1; i <= num % 10; i++) //输出个位 
		printf("%d", i);
	return 0;
}