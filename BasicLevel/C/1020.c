/* 库存量和售价都应用double类型定义 */
#include <stdio.h>
#include <stdlib.h> 

typedef struct {
	double inv, price;
} mooncake; 

int cmp(const void *a, const void *b) { //返回值 < 0，a 被排在 b 前
	mooncake cake1 = *(mooncake *)a;
	mooncake cake2 = *(mooncake *)b;
	return (cake2.price / cake2.inv - cake1.price / cake1.inv) > 0 ? 1 : -1; //括号中计算结果为double型，如果两者相差小于1，直接转换为int将出错
}

int main() {
	int N, D; //月饼的种类数, 市场需求量
	scanf("%d %d", &N, &D);
	mooncake cake[N];
	for(int i = 0; i < N; i++) //读入库存
		scanf("%lf", &cake[i].inv);
	for(int i = 0; i < N; i++) //读入售价
		scanf("%lf", &cake[i].price);
	qsort(cake, N, sizeof(mooncake), cmp);
	double income = 0.0; //收入 
	for(int i = 0; D > 0 && i < N; i++) { //市场仍然有需求，遍历库存 
		if(D <= cake[i].inv) {//如果该月饼能满足需求量 
			income += cake[i].price / cake[i].inv * D;
		} else {//如果该月饼不能满足需求量 
			income += cake[i].price;
		}
		D -= cake[i].inv; //更新需求量 
	}
	printf("%.2f\n", income); 
	return 0;
}