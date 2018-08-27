/*
 * 1. qsort() 函数进阶，自定义判断进行排序
 * 2. 指针和数组的关系
 * 3. 输出时可以 根据排序规律直接输出，不必按照队形排序
 */
#include <stdio.h>
#include <string.h>
#include <stdlib.h>

typedef struct {
	char name[9];
	int height;
} person;
int cmp(const void *a, const void *b) {
	person p1 = *(person *)a;
	person p2 = *(person *)b;
	if (p1.height != p2.height) {//如果身高不同，降序 
		return p2.height - p1.height;
	} else {//身高相同，按名字的字典序升序 
		return strcmp(p1.name, p2.name); 
	}
}
void print(person *p, int num) {//需要输出的人和数量 
	for(int i = num / 2 * 2 - 1; i > 0; i -= 2) {//从大到小的第偶数个都在左边 ，且递增
		printf("%s ", p[i].name);
	}
	int i;
    for(i = 0; i < num - 2; i += 2) {//第奇数个（包括最高）都在右边 ，且递减
		printf("%s ", p[i].name);
	} 
	printf("%s\n", p[i].name);
}
int main(){
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