#include <cstdio>
#include <cctype>

int main() {
	int weight[17] = {7, 9, 10, 5, 8, 4, 2, 1,
					6, 3, 7, 9, 10, 5, 8, 4, 2};
	char M[12] = "10X98765432";
	int N, allRight = 1;
	scanf("%d", &N);
	while(N--) {
		char id[19];
		int Z = 0, isTrue = 1; //权重和，当前身份证号码是否正常
		scanf("%s", id);
		for(int i = 0; i < 17; i++) {
			if(!isdigit(id[i])) { //不是数字 
				isTrue = 0;
				break;
			}
			Z += (id[i] - '0') * weight[i];
		}
		if(isTrue && M[Z % 11] != id[17]) //都是数字 且 校验码无效 
			isTrue = 0;
		if(!isTrue) {
			allRight = 0; 
			printf("%s\n", id);
		} 
	}
	if(allRight) //所有号码正常 
		printf("All passed");
	return 0;
}