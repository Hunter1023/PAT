#include <iostream>
using namespace std; 

int main() {
	int cnt[128] = {0}, c;
	while((c = cin.get()) != EOF)
		cnt[c]++;
	while(cnt['P'] > 0 || cnt['A'] > 0 || cnt['T'] > 0
			|| cnt['e'] > 0 || cnt['s'] > 0 || cnt['t'] > 0) {
		if(cnt['P']-- > 0)
			printf("P");
		if(cnt['A']-- > 0)
			printf("A");
		if(cnt['T']-- > 0)
			printf("T");
		if(cnt['e']-- > 0)
			printf("e");
		if(cnt['s']-- > 0)
			printf("s");
		if(cnt['t']-- > 0)
			printf("t");
	}
	return 0;
}