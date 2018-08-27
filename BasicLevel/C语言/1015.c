/* 本题重点在于排序函数qsort对应的比较函数cmp的构造 */
#include <stdio.h>
#include <stdlib.h>

typedef struct{
	int num, de, cai; //准考证号、德分、才分 
} examinee;
int cmp(const void *a, const void *b) {
	examinee *one = (examinee *)a;
	examinee *tow = (examinee *)b;
	
	if ((one->de + one->cai) != (tow->de + tow->cai)) {
		return (one->de + one->cai) < (tow->de + tow->cai); //比较总分 
	} else if ( one->de != tow->de) {
		return one->de < tow->de; //比较德分 
	} else {
		return one->num > tow->num; //比较准考证号 
	}
}
int main() {
	int N, L, H; //考生总数、最低和最高分数线
	scanf("%d %d %d", &N, &L, &H);
	int num, de, cai; //准考证号、德分、才分 
	int cnt[5] = {0, 0, 0, 0,}; //四类考生的数量 
	examinee order[4][N];
	while (N-- > 0) { //读入考生信息 
		scanf("%d %d %d", &num, &de, &cai);
		if( de >= L && cai >= L) { //如果达到最低分数线 
			examinee e = {num, de, cai}; //创建考生 
			if (de >= H && cai >= H) { //德才全尽 
				order[0][cnt[0]++] = e; 
			} else if (de >= H && cai < H) { //德胜才 
				order[1][cnt[1]++] = e; 
			} else if (de < H && cai < H && de >= cai) {//才德兼亡尚有德胜才 
				order[2][cnt[2]++] = e;
			} else {
				order[3][cnt[3]++] = e;
			} 
		}
	}
	printf("%d\n", cnt[0] + cnt[1] + cnt[2] + cnt[3]);
	for (int i = 0; i < 4; i++) { //遍历四个分类，进行排序 
		qsort(order[i], cnt[i], sizeof(order[i][0]), cmp);
		for (int j = 0; j < cnt[i]; j ++) {//依次输出
			printf("%08d %d %d\n", order[i][j].num, order[i][j].de, order[i][j].cai);
		} 
	}
	return 0; 
}