#include <stdio.h>
#include <stdlib.h>

int cmp(const void *a, const void *b) { //返回值 < 0, a所指元素排在b前(= 0 时，不确定)
    return *(int*)a - *(int*)b; //升序
}

int main() {
    int N, M, K, status; //不相容物品的对数，货品清单的单数，物品件数，是否相容
    int itemlist[1000], pairlist[10000][2] = {{0}};
    scanf("%d %d", &N, &M);
	
    for (int i = 0; i < N; i ++) {// 记录不相容物品清单
        scanf("%d %d", &pairlist[i][0], &pairlist[i][1]);
	}
    for (int i = 0; i < M; i++) {		
        status = 1; // 默认清单中物品相容
        scanf("%d", &K); //物品件数
        for(int j = 0; j < K && status; j++) {//记录物品清单内容
            scanf("%d", &itemlist[j]);
		}
        qsort(itemlist, K, sizeof(int), cmp); //对物品清单排序
        for(int j = 0; j < N; j++) {
            if(bsearch(&pairlist[j][0], itemlist, K, sizeof(int), cmp)
				&& bsearch(&pairlist[j][1], itemlist, K, sizeof(int), cmp)) {// 二分查找 物品清单中是否存在不相容物品
                printf("No\n"); //存在不相容物品
                status = 0;
                break;
            }
        }
		if(status) {
            printf("Yes\n");
		}
    }
    return 0;
}