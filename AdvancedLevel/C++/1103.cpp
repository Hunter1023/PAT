#include <iostream>
#include <vector>
#include <cmath>
using namespace std;

int N, K, P, maxFacSum = 0; //把正整数N 写成 K个正整数的P次幂的和
vector<int> fac, ans, tmpAns;

void DFS(int index, int cnt, int sum, int facSum) {
	if(cnt == K && sum == N) { //找到符合条件的序列
		if(facSum > maxFacSum) { //底数之和更大
			ans = tmpAns; //更新最优底数序列
			maxFacSum = facSum;
		}
		return;
	}
	if(sum > N || cnt > K || index < 1) //和超过N 或 超过K个数 或 遍历完底数序列
		return;
	tmpAns.push_back(index); //将底数存入临时序列tmp
	DFS(index, cnt + 1, sum + fac[index], facSum + index); //选择index的分支
	tmpAns.pop_back(); //不选index的分支
	DFS(index - 1, cnt, sum, facSum);
}

int main() {
	cin >> N >> K >> P;
	for(int i = 0; pow(i, P) <= N; i++) //预处理所有不超过N的数的p次幂
		fac.push_back(pow(i, P));
	DFS(fac.size() - 1, 0, 0, 0); //从fax的最后一位开始往前搜索，以满足 多种结果时，选择底数更大的方案
	if(maxFacSum == 0) { //没有满足条件的序列
		cout << "Impossible" << endl;
	} else {
		cout << N << " = " << ans[0] << '^' << P;
		for(int i = 1; i < ans.size(); i++)
			cout << " + " << ans[i] << '^' << P;
	}
	return 0;
}