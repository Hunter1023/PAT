#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

void downAdjust(vector<int> &heap, int low, int high) {
	int i = low, j = i * 2; //id 为欲调整结点，j 为其左孩子
	while(j <= high) { //存在孩子结点
		if(j + 1 <= high && heap[j + 1] > heap[j]) //选择值最大的子结点
			j = j + 1;
		if(heap[i] >= heap[j]) //子结点不比父结点大，无需调整堆
			break;
		swap(heap[i], heap[j]);
		i = j; //保持i为欲调整结点
		j = i * 2; //j 为其左孩子，向下调整
	}
}

int main() {
	int N;
	vector<int> seq1, seq2;
	cin >> N;
	seq1.resize(N+1);
	seq2.resize(N+1);
	for(int i = 1; i <= N; i++)
		cin >> seq1[i];
	for(int i = 1; i <= N; i++)
		cin >> seq2[i];
	int orderCnt = 1;
	for(int i = 1; i < N && seq2[i] <= seq2[i+1]; i++)
		orderCnt++;
	int isInsert = 1;
	for(int i = orderCnt + 1; i <= N; i++) {
		if(seq1[i] != seq2[i]) {
			isInsert = 0;
			break;
		}
	}
	if(isInsert) {
		cout << "Insertion Sort" << endl;
		sort(seq2.begin() + 1, seq2.begin() + orderCnt + 1); //默认升序
	} else { //堆排序
		cout << "Heap Sort" << endl;
		int index = N; //初始化 未完成堆排序部分第一个 < 堆顶元素的下标
		while(index > 2 && seq2[index] >= seq2[1]) //从后往前找到第一个小于堆顶的元素
			index--;
		swap(seq2[1], seq2[index]);
		downAdjust(seq2, 1, index - 1); //向下调整
	}
	for(int i = 1; i < N; i++) {
		if(i > 1)
			cout << " ";
		cout << seq2[i];
	}
	return 0;
}