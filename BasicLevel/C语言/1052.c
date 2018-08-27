/*
 * 1. 读取符号的方式：每行的长度、内容不一定，不宜构造字符数组，用 getchar() != '\n' 读取字符
 * 2. 读取括号内的字符结束后，添加 '\0' 标记字符串的结束。
 * 3. 有的颜文字 实际大小不止一个字符，选择 [] 的出现次数来统计符号集的长度。
 * 4. 颜文字在命令行窗口存在无法显示的情况，需要提交答案才能真正判断正确性。
 */
#include <stdio.h>

int get(char arr[][5]){
	int i = 0, j = 0, flag = 0, cnt = 0;//存储字符的下标， 是否在方括号[]内,符号的数量 
	char c; 
	while ((c = getchar()) != '\n') {
		if (c == '[') {
			flag = 1;//进入括号内 
			i++;
			j = 0;
			cnt++;//增加符号数量 
		} else if (c == ']') {
			flag = 0;
			arr[i][j] = '\0';//结束字符串 
		} else if (flag == 1) {//字符在[]内 
			arr[i][j++] = c;
		}
	}
	return cnt;
}
int main(){
	char hand[12][5], eye[12][5], mouth[12][5];
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
			printf("%s(%s%s%s)%s\n", hand[lhand], eye[leye], mouth[m], eye[reye], hand[rhand]);
		}
	} 
	return 0;
}