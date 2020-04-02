#include <iostream>
#include <map>
using namespace std;

int G[2000][2000] = {0}, weight[2000] = {0}; //邻接矩阵、点权数组
int N, K, cnt = 0;
string name[2000]; //编号->姓名
int vis[2000] = {0}; //标记是否被访问过
map<string, int> stringToInt; //姓名->编号
map<string, int> gang; //头目->帮派人数

int getId(string str) {
	if(stringToInt.find(str) != stringToInt.end()) //当前姓名已有记录
		return stringToInt[str];
	stringToInt[str] = cnt; //记录姓名对应编号
	name[cnt] = str; //记录编号对应姓名
	return cnt++;
}

void DFS(int nowVisit, int &head, int &memCnt, int &totalW) {
	memCnt++;
	vis[nowVisit] = 1; //标记当前结点已访问
	if(weight[nowVisit] > weight[head])
		head = nowVisit; //更新头目
	for(int i = 0; i < cnt; i++) { //枚举所有人
		if(G[nowVisit][i] > 0) { //有直接联络的帮派成员
			totalW += G[nowVisit][i]; //更新总的边权
			G[nowVisit][i] = G[i][nowVisit] = 0; //删除边，防止回头
			if(vis[i] == 0) //结点i未被访问，则递归访问
				DFS(i, head, memCnt, totalW);
		}
	}
}

void DFSTrave() {
	for(int i = 0; i < cnt; i++) { //枚举所有人
		if(vis[i] == 0) {//未被访问过
			int head = i, memCnt = 0, totalW = 0; //初始化头目，成员数量，图的总边权
			DFS(i, head, memCnt, totalW); //遍历i所在的连通块(整个帮派)
			if(memCnt > 2 && totalW > K) //成员数量 > 2, 总边权 > K，则为帮派
				gang[name[head]] = memCnt; //记录帮派头目及成员数量
		}
	}
}

int main() {
	cin >> N >> K;
	string str1, str2;
	int time;
	for(int i = 0; i < N; i++) {
		cin >> str1 >> str2 >> time;
		int id1 = getId(str1); //将姓名转换为编号
		int id2 = getId(str2);
		weight[id1] += time; //统计点权
		weight[id2] += time;
		G[id1][id2] += time; //统计边权
		G[id2][id1] += time;
	}
	DFSTrave(); //遍历整个图的连通块，获取帮派信息
	cout << gang.size() << endl; //帮派个数
	for(auto it = gang.begin(); it != gang.end(); it++) //遍历输出帮派的头目和人数
		cout << it->first << " " << it->second << endl;
	return 0;
}