#include <cstdio>
#include <string>
using namespace std;

int main() {
	const char pinyin[10][5] = {"ling", "yi", "er", "san", "si",
							"wu", "liu", "qi", "ba", "jiu"};
	int num, sum = 0; 
	while(scanf("%1d", &num) != EOF)
		sum += num;
	string ans = to_string(sum);
	for(int i = 0; i < ans.length(); i++) {
		if(i != 0)
			printf(" ");
		printf("%s", pinyin[ans[i] - '0']);
	}
    return 0;	
}