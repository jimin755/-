#include<iostream>

// 이친수 점화식
// pri [0] =0 pri[1]=1 이고 i>1일때
//pri[i]=pri[i-1]+pri[i-2]

using namespace std;
int main(void) {

	int n = 0;
	cin >> n;

	long *pri = new long[n+1];

	pri[0] = 0;
	pri[1] = 1;
	for (int i = 2; i <= n; i++) {
		pri[i] = pri[i - 1] + pri[i - 2];
	}
	cout << pri[n] << endl;
}
