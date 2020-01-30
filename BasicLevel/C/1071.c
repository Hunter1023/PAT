/* 题目漏洞：输出格式中，句子间隔为1个空格；输出样例中，句子间隔为2个空格。
 * 实际为2个空格 
 */
#include <stdio.h>

int main() {
	int x, K;//筹码数，游戏次数
	scanf("%d %d", &x, &K);
	int n1, n2, b, t;//先后给出的两个整数，玩家的判断，下注量 
	for (int i = 0; i < K; i++) {
		scanf("%d %d %d %d", &n1, &b, &t, &n2);
		if (t > x) {//下注超过持有量 
			printf("Not enough tokens. Total = %d.\n", x);
		} else if ((b == 0 && n2 < n1) || (b == 1 && n2 > n1)) {//玩家赢 
			x += t;
			printf("Win %d! Total = %d.\n", t, x);
		} else {//玩家输 
			x -= t; 
			printf("Lose %d. Total = %d.\n", t, x);
			if (x <= 0) {//玩家输光 
				printf("Game Over.\n");
				break;
			} 
		}
	}
	return 0;
}