#include <stdio.h>
#include <math.h>

int main() {
	int N;//射击人数
	scanf("%d", &N);
	int best_id, best_d = 200, worst_id, worst_d = 0;//最好的距离和id， 最差的距离和id 
	for (int i = 0; i < N; i++) {
		int id, x, y;
		scanf("%d %d %d", &id, &x, &y);
		double d = sqrt(x * x + y * y);//离靶心的距离 
		if (d < best_d) {
			best_d = d;
			best_id = id;
		} 
		if (d > worst_d) {
			worst_d = d;
			worst_id = id;
		}
	}
	printf("%04d %04d", best_id, worst_id);
	return 0;
}