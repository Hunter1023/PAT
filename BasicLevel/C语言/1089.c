#include <stdio.h>
#include <stdlib.h>

int main() {
    int N; //玩家个数 
    scanf("%d",&N);
    int state[N+1], identity[N+1], Lier[N+1], nLier;
    for(int i = 1; i <= N; i++) { //记录每个玩家的陈述 
        scanf("%d",&state[i]);
    } 
    for(int i = 1; i < N; i++) {
        for(int j = i+1; j <= N; j++) {
            for(int k = 1; k <= N; k++) {
            	identity[k] = Lier[k] = 0;
			}
            identity[i] = identity[j] = 1, nLier = 0;
            for(int k = 1 ; k <= N && nLier <= 2 ; k++) {
            	if(identity[abs(state[k])] != (state[k] < 0)) {
					Lier[nLier++] = k;
				} 
            	if(nLier == 2 && identity[Lier[0]] + identity[Lier[1]] == 1) {
                	printf("%d %d", i, j);
                	return 0;
            	}
			}
        }
    } 
    printf("No Solution");
}

