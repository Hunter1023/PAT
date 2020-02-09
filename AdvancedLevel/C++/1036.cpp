#include <cstdio>

typedef struct {
	char name[11];
	char gender;
	char ID[11];
	int grade;
} student;

int main() {
	int N, min = 101, max = -1, maxIndex, minIndex;
	scanf("%d", &N);
	student s[N];
	for(int i = 0; i < N; i++) {
		scanf("%s %c %s %d", s[i].name, &s[i].gender, s[i].ID, &s[i].grade);
		if(s[i].gender == 'M' && s[i].grade < min) {
				minIndex = i;
				min = s[i].grade;
		} else if(s[i].gender == 'F' && s[i].grade > max) {
				maxIndex = i;
				max = s[i].grade;
		} 
	}
	if(max == -1) {
		printf("Absent\n");
	} else {
		printf("%s %s\n", s[maxIndex].name, s[maxIndex].ID);
	}
	if(min == 101) {
		printf("Absent\n");
	} else {
		printf("%s %s\n", s[minIndex].name, s[minIndex].ID);
	}
	if(max == -1 || min == 101) {
		printf("NA\n");
	} else {
		printf("%d", max - min);
	}
	return 0;
}