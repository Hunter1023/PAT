#include <stdio.h>
#include <stdlib.h>

int main() {
    int N; //玩家个数 
    scanf("%d",&N);
    int remark[N+1], status[N+1], liar[3], liarNum; // 发言，身份，说谎者，说谎人数
    for(int i = 1; i <= N; i++) { //记录发言 
        scanf("%d", &remark[i]);
    } 
    for(int i = 1; i < N; i++) {
        for(int j = i + 1; j <= N; j++) {
            for(int k = 1; k <= N; k++) { //初始化所有人的身份为好人，没有说谎者
            	status[k] = 0;
			}
            status[i] = status[j] = 1, liarNum = 0; // 假设i和j是狼人，说谎人数初始化为0
            for(int k = 1; k <= N && liarNum <= 2; k++) { // 在说谎人数 <= 2 的前提下，依次判断发言
            	if((remark[k] < 0) != status[abs(remark[k])]) { // 发言与所指对象身份不符时，发言者即为说谎者
					liar[liarNum++] = k; // 记录说谎者
				} 
			}
			if(liarNum == 2 && status[liar[0]] + status[liar[1]] == 1) { // 一共两个说谎者 且 两个说谎者只有一个是狼人
				printf("%d %d", i, j); // 输出 狼人
				return 0;
			}
        }
    } 
    printf("No Solution");
	return 0;
}
