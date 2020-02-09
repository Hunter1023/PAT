#include <iostream>
using namespace std;

int main() {
	int M; //num of records
	cin >> M;
	string tmpId, firstId, lastId, tmpT1, firstTime = "23:59:60", tmpT2, lastTime = "00:00:00";
	while(M--) {
		cin >> tmpId >> tmpT1 >> tmpT2;
		if(tmpT1 < firstTime) {
			firstId = tmpId;
			firstTime = tmpT1;
		}
		if(tmpT2 > lastTime) {
			lastId = tmpId;
			lastTime = tmpT2;
		}
	}
	cout << firstId << " " << lastId;
	return 0;
}