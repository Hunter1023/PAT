#include<stdio.h>

int main() {
    int cnt;
    scanf("%d",&cnt); // 读入数字的数量 
    int a[cnt]; //创建存放数字的数组 
    for(int i = 0; i < cnt; i++) {
        scanf("%d", &a[i]);
    }
    //筛选关键数字
    for(int i = 0; i < cnt; i++) { 
        int num = a[i];
        while(num != 1) {
            if(num % 2 == 0) {
				num /= 2;
			} else {
				num = (3*num + 1) / 2;
			}
            for(int j = 0; j < cnt; j++) {//遍历数组，如果是被覆盖的数，变为1
                if(a[j] == num) {
                    a[j] = 1;//1<n<=100
                    break;// 因为数组的数字各不相同，找到被覆盖的即可跳出循环
                }
            }
        }
    }
    //降序 冒泡排序 
    for (int i = 0; i < cnt; i++) {
    	for (int j = 0; j < cnt - i - 1; j++) {
    		if (a[j] < a[j+1]) {
    			int temp = a[j];
    			a[j] = a[j+1];
    			a[j+1] = temp;
			}
		}
	} 
    //输出关键字 
	for (int i = 0; a[i] != 1 && i < cnt; i++) {
		if(i != 0) {
			printf(" ");
		}
		printf("%d", a[i]); 
	} 
}