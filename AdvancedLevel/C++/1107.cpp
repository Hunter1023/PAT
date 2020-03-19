#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

vector<int> father, cluster; //存放父结点，统计各集合中的人数

int findFather(int x) {
	int a = x; //为了后续路径压缩
	while(father[x] != x) //找到根结点
		x = father[x];
	while(father[a] != a) { //路径压缩
		int tmp = father[a]; //保存父结点
		father[a] = x; //a的父结点指向根结点
		a = tmp; //更新为原父结点
	}
	return x;
}

void Union(int a, int b) {
	int faA = findFather(a);
	int faB = findFather(b);
	if(faA != faB)
		father[faA] = faB;
}

bool cmp(int a, int b) { //降序
	return a > b;
}

int main() {
	int N, K, h, cnt = 0;
	int hobby[1001] = {0}; //记录 任意一个 拥有对应爱好的结点
	cin >> N;
	father.resize(N + 1);
	cluster.resize(N + 1);
	for(int i = 1; i <= N; i++)
		father[i] = i;
	for(int i = 1; i <= N; i++) {
		scanf("%d:", &K);
		while(K--) {
			cin >> h;
			if(hobby[h] == 0) //还没有人有当前爱好
				hobby[h] = i; //记录 i 拥有当前爱好
			Union(i, hobby[h]); //合并有共同爱好的人
		}
	}
	for(int i = 1; i <= N; i++)
		cluster[findFather(i)]++; //统计各集合中的人数
	sort(cluster.begin(), cluster.end(), cmp);
	for(int i = 0; i < N && cluster[i] > 0; i++) //统计集合个数
		cnt++;
	cout << cnt << endl;
	for(int i = 0; i < cnt; i++) {
		if(i > 0)
			cout << " ";
		cout << cluster[i];
	}
	return 0;
}