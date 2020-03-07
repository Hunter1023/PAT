#include <iostream>
#include <algorithm>
using namespace std; 

typedef struct {
	double inventory, price;
} mooncake;

bool cmp(mooncake m1, mooncake m2) {
	return m1.price / m1.inventory > m2.price / m2.inventory;
}

int main() {
	int N, D;
	cin >> N >> D;
	mooncake m[N];
	for(int i = 0; i < N; i++)
		cin >> m[i].inventory;
	for(int i = 0; i < N; i++)
		cin >> m[i].price;
	sort(m, m + N, cmp);
	double profit = 0;
	for(int i = 0; D > 0 && i < N; i++) {
		if(D > m[i].inventory) {
			profit += m[i].price;
		} else {
			profit += m[i].price / m[i].inventory * D;
		}
		D -= m[i].inventory;
	}
	printf("%.2f\n", profit); 
	return 0; 
}