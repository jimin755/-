#include<iostream>
#include<algorithm>

// 규칙 n/2+n%2
using namespace std;
int main(void) {

	int kim = 0; 
	int lm = 0;
	int num = 0;
	int round = 0;

	cin >>num >> kim >> lm;

	int maxV = max(kim, lm);
	int minV = min(kim, lm);
	if (num > 0 && num <= 100000) {
		while (minV>0) {
			round++;
			if ((maxV - minV == 1) && (maxV % 2 == 0) && (minV % 2 != 0)) {
				cout << round << endl;
				return 0;
			} // 붙는 라운드
			else {
				maxV = (maxV / 2) + (maxV % 2);
				minV = (minV / 2) + (minV % 2);
			} // 둘이 안붙는 라운드 진행
		}
		cout << "-1" << endl;
	}
	return 0;
}
