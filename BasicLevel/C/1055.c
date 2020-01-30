/*
 * 1. 利用指针和数组的特点；
 * 2. 排序规律：
 *   2.1 人数为 N/K 的共有 K-1排；
 *	 2.2 身高从前排到后排升序；
 *	 2.3 每排从大到小的第偶数个都在左边，且递增；
 *   2.4 每排第奇数个（包括最高）都在右边，且递减；
 * 3. 输出时可以 根据排序规律直接输出，不必按照队形排序；
 */
#include <stdio.h>
#include <string.h>
#include <stdlib.h>

typedef struct {
	char name[9]; // 名字
	int height; // 身高
} person;
int cmp(const void *a, const void *b) {
	person p1 = *(person *)a;
	person p2 = *(person *)b;
	if (p1.height != p2.height) {//身高降序 
		return p2.height - p1.height;
	} else {//名字的字典序升序 
		return strcmp(p1.name, p2.name); 
	}
}
void print(person *p, int num) {//需要输出的人和数量 
	int i;
	for(i = num / 2 * 2 - 1; i > 0; i -= 2) {//从大到小的第偶数个都在左边 ，且递增
		printf("%s ", p[i].name);
	}
    for(i = 0; i < num - 2; i += 2) {//第奇数个（包括最高）都在右边 ，且递减
		printf("%s ", p[i].name);
	} 
	printf("%s\n", p[i].name);
}
int main() {
	int N, K;//总人数，总排数
	scanf("%d %d", &N, &K);
	person people[N];
	for (int i = 0; i < N; i++) {
		scanf("%s %d", &people[i].name, &people[i].height);
	}
	qsort(people, N, sizeof(person), cmp);
	int remain = N - N / K * (K-1);//多出来的人先输出 
	person *p = people;
	print(p, remain);
	p += remain;
	for (int i = 0; i < K - 1; i++) {//其余每排  N/K 人排序 
		print(p, N/K);
		p += N/K; 
	}
	return 0;
}