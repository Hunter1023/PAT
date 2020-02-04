#include <cstdio>

int main() {
	int N;
	while (scanf("%d", &N) != EOF) {
		int dis[N+1] = {0}, M, length = 0; //dis[i]记录出口1到第（i+1）%N个结点的距离 
		for (int i = 1; i <= N; i++) {
			int tmp; 
			scanf("%d", &tmp);
			length += tmp;
			dis[i] = length;
		}
		scanf("%d", &M);
		while (M--) {
			int d = 0, e1, e2, tmp; //距离，出口1和2 
			scanf("%d %d", &e1, &e2);
			if (e1 > e2) {
				tmp = e1;
				e1 = e2;
				e2 = tmp;
			}
			d = dis[e2 - 1] - dis[e1-1];
			printf("%d\n", d < (length - d) ? d : (length - d));
		}
	}
	return 0;
}
