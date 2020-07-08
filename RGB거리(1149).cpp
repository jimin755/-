#include<iostream>

//점화식 
//minCost[i][0] = min(minCost[i - 1][1], minCost[i - 1][2]) + cost[i][0];
//minCost[i][1] = min(minCost[i - 1][0], minCost[i - 1][2]) + cost[i][1];
//minCost[i][2] = min(minCost[i - 1][0], minCost[i - 1][1]) + cost[i][2];
//  i!=0 if i==0
//minCost[i][0] = cost[i][0];
//minCost[i][1] = cost[i][1];
//minCost[i][2] = cost[i][2];

// 아래 코드는 minCost와 cost를 이차원배열 하나로 해결 

// #define MIN(a,b) a<b?a:b 매크로 함수

using namespace std;
int minCom(int n1, int n2) {
	if (n1 > n2) {
		return n2;
	}
	else {
		return n1;
	}
}
int main(void) {
	int n = 0;
	cin >> n;
	if (n <= 1000) {
		if (n <= 0) {
			cout << 0 << endl;
			return 0;
		}
		int ** cost = new int *[n];
		for (int i = 0; i < n; i++) {
			cost[i] = new int[n];
		}
		// cost[n-1번째집][0=R 1=G 2 =B]
		for (int i = 0; i < n; i++) {
			cin >> cost[i][0] >> cost[i][1] >> cost[i][2];
		}
		for (int i = 1; i < n; i++) {
			cost[i][0] = minCom(cost[i - 1][1], cost[i - 1][2]) + cost[i][0];
			cost[i][1] = minCom(cost[i - 1][0], cost[i - 1][2]) + cost[i][1];
			cost[i][2] = minCom(cost[i - 1][0], cost[i - 1][1]) + cost[i][2];
		}
		cout << minCom(minCom(cost[n - 1][0], cost[n - 1][1]), cost[n - 1][2]) << endl;
	}
	return 0;
}
