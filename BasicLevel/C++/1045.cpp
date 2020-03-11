#include <iostream>
using namespace std;

int main() {
	int N;
	cin >> N;
	int arr[N], ans[N], leftMax[N] = {0}, rightMin[N];
	fill(rightMin, rightMin + N, 1e9 + 1); //初始化每个元素的右侧最小值 
	for(int i = 0; i < N; i++) {
		cin >> arr[i];
		if(i > 0) //确定每个元素左侧的最大值
			leftMax[i] = max(arr[i-1], leftMax[i-1]);
	}
	for(int i = N - 2; i >= 0; i--) //确定每个元素的右侧最小值 
		rightMin[i] = min(arr[i+1], rightMin[i+1]);
	int cnt = 0;
	for(int i = 0; i < N; i++) { 
		if(arr[i] > leftMax[i] && arr[i] < rightMin[i]) //符合要求的元素必然为递增顺序 
			ans[cnt++] = arr[i];
	}
	cout << cnt << endl;
	for(int i = 0; i < cnt; i++) {
		if(i > 0)
			cout << ' '; 
		cout << ans[i];
	}
	cout << endl; //即使没有主元，也得换行 
	return 0;
}