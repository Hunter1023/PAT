#include <iostream>
#include <algorithm>
using namespace std;

int main() {
	int N;
	cin >> N;
	int arr1[N], arr2[N];
	for(int i = 0; i < N; i++)
		cin >> arr1[i];
	for(int i = 0; i < N; i++)
		cin >> arr2[i];
	int orderCnt =  1; //有序的数量
	for(int i = 0; i < N - 1 && arr2[i] <= arr2[i+1]; i++) //统计中间序列有序的数量 
		orderCnt++;
	int isInsert = 1; //是否为插入排序 
	for(int i = orderCnt + 1; i < N; i++) { //插入排序：未排序部分和初始序列一定相同
		if(arr1[i] != arr2[i]) {
			isInsert = 0;
			break;
		} 
	} 
	if(isInsert) { //插入排序 
		cout << "Insertion Sort" << endl;
		sort(arr1, arr1 + orderCnt + 1); 
	} else { //归并排序 
		cout << "Merge Sort" << endl;
		int flag = 1; //循环的标记 
		for(int step = 2; flag && step / 2 < N; step *= 2) { //每 step 个元素一组 
			flag = 0;
            for(int i = 0; i < N; i++) { //比较两个序列  
                if(arr1[i] != arr2[i]) { //如果有元素不同，继续归并 
                    flag = 1;
                    break; 
                }
            }
			for(int i = 0; i < N; i += step) //归并排序 
				sort(arr1 + i, arr1 + min(i + step, N)); //末尾分组的元素个数可能不足step 
		}
	}
	for(int i = 0; i < N; i++) {//输出数组
		if(i != 0)
			cout << " ";
		cout << arr1[i];
	}
	return 0;
}