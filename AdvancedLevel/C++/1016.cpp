#include <iostream>
#include <algorithm>
using namespace std;

typedef struct{
	string name;
	int month, day, hour, min, time;
	int status;
} record;

bool cmp(record a, record b) { //返回值为true时，a被排在b之前
	if(a.name != b.name) {
		return a.name < b.name; //也可以 b.name.compare(a.name)
	} else {
		return a.time < b.time;
	}
}

double getCost(record r1, record r2, int toll[]) {
	int cost = 0;
	while(r1.day != r2.day || r1.hour != r2.hour || r1.min != r2.min) {
		r1.min++;
		cost += toll[r1.hour];
		if(r1.min == 60) {
			r1.min = 0;
			r1.hour++;
		}
		if(r1.hour == 24) {
			r1.hour = 0;
			r1.day++;
		}
	}
	return cost;
}

int main() {
	int toll[24], N;
	for(int i = 0; i < 24; i++)
		cin >> toll[i];
	cin >> N;
	record r[N];
	string tmp;
	for(int i = 0; i < N; i++) {
		cin >> r[i].name;
		scanf("%d:%d:%d:%d", &r[i].month, &r[i].day,
				&r[i].hour, &r[i].min);
		cin >> tmp;
		r[i].status = (tmp == "on-line") ? 1 : 0;
		r[i].time = r[i].day * 24 * 60 + r[i].hour * 60 + r[i].min;
	}
	sort(r, r + N, cmp);
	int total = 0, hasCalled = 0;
	string preName = {0};
	for(int i = 0; i < N - 1; i++) {
		if(r[i].name == r[i+1].name //同一用户 且 为先通话后挂断的状态 
			&& r[i].status == 1 && r[i+1].status == 0) {
			if(r[i].name != preName) { //新用户 
				if(hasCalled) //上一个用户有正常的通话记录
					printf("Total amount: $%.2f\n", total * 0.01); //输出总费用
				cout << r[i].name << " ";
				printf("%02d\n", r[i].month); //输出当前用户的名字和通话月份
				preName = r[i].name;
				total = 0; 
			}
			hasCalled = 1; //已有人员的正常通话记录
			int cost = getCost(r[i], r[i+1], toll);
			total += cost;
			printf("%02d:%02d:%02d %02d:%02d:%02d %d $%.2f\n", r[i].day, r[i].hour, r[i].min,
					r[i+1].day, r[i+1].hour, r[i+1].min, r[i+1].time - r[i].time, cost * 0.01);
		}
	} 
	if(hasCalled) //上一个用户有正常的通话记录
		printf("Total amount: $%.2f\n", total * 0.01); //输出总费用
	return 0;
} 