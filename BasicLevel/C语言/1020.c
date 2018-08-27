/* 本题重点在于考虑 全部库存仍无法满足需求 的情况 */
#include <stdio.h>

typedef struct {
	double inv;//库存 
	double price;//售价 
} mooncake; 
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
	for (int i = 0; i < N - 1; i++) {//月饼按单价降序排序
		for (int j = 0; j < N-i-1; j++) {
			if ((cake[j].price / cake[j].inv) < (cake[j+1].price / cake[j+1].inv)) {
				mooncake temp = cake[j];
				cake[j] = cake[j+1];
				cake[j+1] = temp;
			}
		}
	} 
	int i = 0;//月饼的种类下标
	double income = 0.0;//收入 
	while (D > 0 && i < N) {//如果还有需求量没有满足 , 或者所有库存仍然无法满足需求 
		if (D <= cake[i].inv) {//如果该月饼能满足需求量 
			income += D * (cake[i].price /  cake[i].inv);
			D = 0;
		} else {//如果该月饼不能满足需求量 
			income += cake[i].price;
			D -= cake[i++].inv; //更新需求量 
		}
	}
	printf("%.2f\n", income); 
	return 0;
}