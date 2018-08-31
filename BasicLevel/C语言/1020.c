/* 
 * 1. 最大收益 —— 单价从高到低 出货
 * 2. 需要考虑 全部库存仍无法满足需求 的情况 
 */
#include <stdio.h>
#include <stdlib.h> 

typedef struct {
	double inv;//库存 
	double price;//售价 
} mooncake; 
int cmp(const void *a, const void *b) {
	mooncake cake1 = *(mooncake *)a;
	mooncake cake2 = *(mooncake *)b;
	return cake2.price / cake2.inv > cake1.price / cake1.inv; //按单价降序 
}
int main() {
	int N, D;//月饼的种类数, 市场需求量
	scanf("%d %d", &N, &D);
	mooncake cake[N];//月饼的种类 
	for (int i = 0; i < N; i++) {//读入库存
		scanf("%lf", &cake[i].inv);
	}
	for (int i = 0; i < N; i++) {//读入售价
		scanf("%lf", &cake[i].price);
	}
	qsort(cake, N, sizeof(mooncake), cmp);
	double income = 0.0;//收入 
	for (int i = 0; i < N && D > 0; i++) {//市场仍然有需求，遍历库存 
		if (D <= cake[i].inv) {//如果该月饼能满足需求量 
			income += D * (cake[i].price / cake[i].inv);
			D = 0;
		} else {//如果该月饼不能满足需求量 
			income += cake[i].price;
			D -= cake[i].inv; //更新需求量 
		}
	}
	printf("%.2f\n", income); 
	return 0;
}