#include <cstdio>

typedef struct {
	char name[11];
	char id[11];
	int scores;
} student;

int main() {
	int n, max = -1, min = 101, maxId, minId;
	scanf("%d", &n);
	student s[n];
	for(int i = 0; i < n; i++) {
		scanf("%s %s %d", s[i].name, s[i].id, &s[i].scores);
		if(s[i].scores > max) {
			max = s[i].scores;
			maxId = i;
		}
		if(s[i].scores < min) {
			min = s[i].scores;
			minId = i;
		}
	}
	printf("%s %s\n", s[maxId].name, s[maxId].id);
	printf("%s %s\n", s[minId].name, s[minId].id);
	return 0;
}