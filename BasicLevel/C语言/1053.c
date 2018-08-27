/* 确认好浮点数和整数。其中输出是天数相除得到百分比，需要 从整数到浮点数的转换 */
#include <stdio.h>

int main(){
	int N, D;//住房总套数，观察天数阈值 
	double e;//低电量阈值 
	scanf("%d %lf %d", &N, &e, &D);
	int isvac = 0, mayvac = 0;//空置数量，可能空置数量 
	for (int i = 0; i < N; i++) {
		int day, D_cnt = 0;//观察天数，低于电量阈值的天数
		double elec;//检测的电量 
		scanf("%d", &day);
		for (int j = 0; j < day; j++) {
			scanf("%lf", &elec);
			if (elec < e) {
				D_cnt++;
			}
		} 
		if (D_cnt * 2 > day && day > D) {//超过一半的日子用电量低于阈值 且 观察期超过给定阈值
				isvac++;
		} else if (D_cnt * 2 > day) {//超过一半的日子用电量低于阈值
			mayvac++;
		}
	}
	printf("%.1f%% %.1f%%\n", mayvac * 100.0 / N, isvac * 100.0 / N);//天数相除 是 整数相除，注意 
	return 0;
}