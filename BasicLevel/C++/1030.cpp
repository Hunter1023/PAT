#include <iostream>
#include <algorithm> 
using namespace std;

int main() {
	int N, p;
	cin >> N >> p;
	long long arr[N];
	for(int i = 0; i < N; i++)
		cin >> arr[i];
	sort(arr, arr + N); //默认升序 
	int maxCnt = 0, m = 0, M = N - 1;
	for(int i = 0; i + maxCnt < N; i++) { //数列未取完
		for(int j = i + maxCnt; j < N; j++) { //超过完美数列数字个数，是否为完美数列
			if(arr[j] <= (arr[i] * p)) {
				maxCnt++;
			} else { //如果不是，后续元素更大，更不可能是，跳出循环即可
				break;
			}
		} 
	}
	cout << maxCnt << endl;
	return 0;
}