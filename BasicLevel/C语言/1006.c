#include <stdio.h>

int main() {
	int num;
	scanf("%d", &num);
	
	int a[3];
	for(int i = 0; i < 3; i++) {
		a[i] = num % 10;// a[0]存个位；a[1]存十位；a[2]存百位 
		num /= 10; 
	}
	
	for (int i = 0; i < a[2]; i++) {
		printf("B");
	} 
	for (int i = 0; i < a[1]; i++) {
		printf("S");
	}
	for (int i = 0; i < a[0]; i++) {
		printf("%d", i+1);
	} 
	return 0;
}