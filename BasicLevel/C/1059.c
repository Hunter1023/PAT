#include <stdio.h>
#include <math.h>

typedef struct {
	int isChecked;//是否已兑奖
	int id; 
} rank; 
int ranking(int id, rank *arr, int length) {
	for (int i = 1; i < length; i++) {
		if (arr[i].id == id) {
			return i;//返回排名 
		}
	}
	return 0;//不存在该id 
} 
int isPrime(int r) {//数字
	if (r == 2) {
		return 1;
	} else if (r % 2 == 0) {
		return 0;
	}
	for (int i = 3; i <= sqrt(r); i += 2) {
		if (r % i == 0) {
			return 0;
		}
	}
	return 1;
}
int main(){
	int N, K;//参赛人数，需要查询的ID数量 
	char reward[5][17] = {"Mystery Award", "Minion", "Chocolate", "Are you kidding?", "Checked"};
	scanf("%d", &N);
	rank arr[N+1];
	for (int i = 1; i < N + 1; i++) {//读取排名 
		scanf("%d", &arr[i].id);
		arr[i].isChecked = 0;
	}
	scanf("%d", &K);
	for (int i = 0; i < K; i++) {
		int id;
		scanf("%d", &id);
		printf("%04d: ", id);
		int r = ranking(id, arr, N+1);//获取排名
		if (r == 0) {//ID不在名单中 
			printf("%s\n", reward[3]); 
		} else if (arr[r].isChecked){//已经兑奖	
			printf("%s\n", reward[4]);
		} else {
			arr[r].isChecked = 1;//已兑奖 
			if (r == 1) {//冠军 
				printf("%s\n", reward[0]);
			} else if (isPrime(r)) {//是素数 
				printf("%s\n", reward[1]);
			} else {
				printf("%s\n", reward[2]);
			}
		} 
	}
	return 0;
}