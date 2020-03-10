#include <iostream>
#include <algorithm> 
using namespace std;

const int MAX_PRICE = 1e9;

typedef struct {
	double price, dis;
} station;

bool cmp(station s1, station s2) { //按距离升序 
	return s1.dis < s2.dis;
}

int main() {
	double maxC, D, avgD;
	int N;
	cin >> maxC >> D >> avgD >> N;
	station s[N+1];
	s[0] = {0, D}; //将终点作为加油站 
	for(int i = 1; i <= N; i++)
		cin >> s[i].price >> s[i].dis;
	sort(s, s + N + 1, cmp);
	if(s[0].dis != 0) { //出发点没有加油站 
		 cout << "The maximum travel distance = 0.00" << endl; 
	} else { //出发点有加油站
		int now = 0, isFail = 0; //当前加油站编号，是否无法到达终点  
		double maxDis = maxC * avgD, totalPrice = 0, nowC = 0; //满油的行驶距离，总花费、当前油量 
		while(s[now].dis < D) { //还没到达终点
			if(maxDis < s[now+1].dis - s[now].dis) { //到不了之后的加油站 
				printf("The maximum travel distance = %.2f\n", s[now].dis + maxDis); 
				isFail = 1; //无法到达终点 
				break;
			}
			double minPrice = MAX_PRICE; //初始化后续最低油价
			int index = -1; //后续最低油价站点的下标 
			for(int i = now + 1; s[i].dis - s[now].dis <= maxDis && i <= N; i++) { //能去到的最远距离内 
				if(s[i].price < minPrice) { //查找最低油价 
					minPrice = s[i].price;
					index = i; 
					if(minPrice < s[now].price) //油价比当前更低
						break;
				}
			}
			double need = (s[index].dis - s[now].dis) / avgD;
			if(minPrice < s[now].price) { //有更低的油价 
				if(nowC < need) { //油箱里油不够 
					totalPrice += (need - nowC) * s[now].price; //只加刚好能去对应加油站的油 
					nowC = 0; 
				} else { //不用加油 
					nowC -= need;
				}
			} else { //没有更低的油价 
				totalPrice += (maxC - nowC) * s[now].price; //加满油
				nowC = maxC - need; //到达对应加油站后，更新剩余油量 
			}
			now = index; 
		}
		if(!isFail) //可以到达终点 
			printf("%.2f\n", totalPrice);
	}
	return 0;
}