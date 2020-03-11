#include <iostream>
#include <stack>
using namespace std;

int main() {
	int M, N, K;
	cin >> M >> N >> K;
	int seq[N+1];
	for(int i = 0; i < K; i++) {
		stack<int> s;
		for(int j = 1; j <= N; j++) //读入弹出的序列 
			cin >> seq[j];
		int index = 1;
		for(int j = 1; j <= N; j++) { //将数字按顺序入栈
			s.push(j); //入栈
			if(s.size() > M) //堆栈溢出
				break;
			while(!s.empty() && s.top() == seq[index]) { //栈不为空，且栈顶元素 和 当前需要出栈的元素相同
				s.pop();
				index++;
			}
		}
		if(index == N + 1) { //序列全部出栈
			cout << "YES" << endl;
		} else {
			cout << "NO" << endl;
		}
	}
	return 0;
}