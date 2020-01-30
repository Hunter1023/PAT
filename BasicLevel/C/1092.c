#include <stdio.h>

int main() {
    int N, M; //月饼的种类数，城市数量
    scanf("%d %d", &N, &M);
	int sales[1001] = {0}, tmp, max = 0; //销量数组，临时记录输入，最大销量
    for (int i = 0; i < M; i++) {
        for (int j = 1; j <= N; j++) {
            scanf("%d", &tmp);
            sales[j] += tmp;
        }
    }
    for (int i = 1; i <= N; i++) {//获取最大销量
        if(max < sales[i]) {
            max = sales[i];
		}
	}
    printf("%d\n", max);
    for (int i = 1, cnt= 0; i <= N; i++) {//输出冠军
        if(sales[i] == max) {
        	if (cnt) {
    			printf(" ");
			}
            printf("%d", i);
            cnt++;
		}
	}
    return 0;
}