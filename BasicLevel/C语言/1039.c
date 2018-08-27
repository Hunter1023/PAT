/* 待优化对珠子的判断 */
#include <stdio.h>
#include <ctype.h>
#include <string.h>

int main() {
	int color[2][62] = {0, 0};//珠串一共有62种不同的颜色
	char line[2][1001];
	scanf("%s\n%s", line[0], line[1]);
	for (int i = 0; i < 2; i++) {
		for (int j = 0; j < strlen(line[i]); j++) {
			if (isupper(line[i][j])) {
				color[i][line[i][j]-'A'+36]++;
			} else if (islower(line[i][j])) {
				color[i][line[i][j]-'a'+10]++;
			}else {
					color[i][line[i][j]-'0']++;
			}
		}
	}
	int lack = 0, surplus = 0, isenough = 1; 
	//如果小红 要的颜色都有，输出多余的珠子个数；否则输出 缺少的珠子个数 
	for (int i = 0; i < 62; i++) {
		if (color[1][i] == 0) {//如果不是小红要的颜色 
			surplus +=  color[0][i]; 
		} else {//是小红要的颜色 
			if (color[1][i] - color[0][i] <= 0) {//如果该颜色珠子足够 
				surplus += color[0][i] - color[1][i]; 
			} else {//珠子颜色不够 
				isenough = 0; 
				lack +=  color[1][i] - color[0][i]; 
			}
		}
	}
	if (isenough) {
		printf("Yes %d\n", surplus);
	} else {
		printf("No %d\n", lack);
	}
	return 0;
}