/*
 * 1. 读取符号
 *		- getchar() != '\n';
 * 		- 正则表达式 "%[^]]" 读取符号;
 * 		- 统计符号集的长度;
 * 2. 颜文字 实际大小可能不止一个字符
 * 3. 颜文字在命令行窗口存在无法显示的情况，需要提交答案才能真正判断正确性;
 */
#include <stdio.h>

int get(char arr[][5]){
	int i = 0;//存储符号的下标
	char c; 
	while ((c = getchar()) != '\n') {
		if (c == '[') {
			scanf("%[^]]", arr[i++]);//读入 ']' 之前的字符 
		}
	}
	return i;
}
int main(){
	char hand[10][5], eye[10][5], mouth[10][5];
	int cnt_hand = get(hand);
	int cnt_eye = get(eye);
	int cnt_mouth = get(mouth);
	int K;//用户请求的个数
	scanf("%d", &K);
	while (K-- > 0) {
		int lhand, leye, m, reye, rhand;
		scanf("%d %d %d %d %d", &lhand, &leye, &m, &reye, &rhand);
		if (lhand > cnt_hand || lhand < 1 || leye > cnt_eye 
			|| leye < 1 || m > cnt_mouth || m < 1 || reye > cnt_eye || reye < 1 
			|| rhand > cnt_hand || rhand < 1 ) {
			printf("Are you kidding me? @\\/@\n");
		} else {
			printf("%s(%s%s%s)%s\n", hand[lhand-1], eye[leye-1], mouth[m-1], eye[reye-1], hand[rhand-1]);
		}
	} 
	return 0;
}