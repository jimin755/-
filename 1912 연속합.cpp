#include<iostream>
#include<algorithm>
#include<vector>

using namespace std;

int main(void) {
	int n;
	cin >> n;
	int dpV = 0;
	int maxV = 0, v = 0;
	for (int i = 0; i < n; i++) {
		//cin >> v;
		scanf("%d", &v);
		if (i == 0) {
			maxV = v;
			dpV = v;
		}
		else {
			dpV = max(dpV + v, v);
			maxV = max(maxV, dpV);
		}
	}
	cout << maxV;
	return 0;
}
// �޸� �ּ�ȭ�� ���� ���� �ڵ��� �ٸ��� �迭�� �� �Ϲ� ������ ���� 2000 8ms
// �ð� �ּ�ȭ�� ���� �Է°� ����ȭ �� ����� ���ÿ� �����ϸ� cin ��� scanf�� ����Ͽ� �Է� �ð� ���

/*
#include<iostream>
#include<algorithm>
#include<vector>

using namespace std;

int main(void) {
	int n;
	cin >> n;
	vector<int> dp(n, 0);
	int maxV = 0 , v =0;
	for (int i = 0; i < n; i++) {
		cin >> v;
		if (i == 0) {
			maxV = v;
			dp.at(0) = v;
		}
		else {
			dp[i] = max(dp.at(i - 1) + v, v);
			maxV = max(maxV, dp[i]);
		}
	}
	cout << maxV;
	return 0;
}
2400
8ms
*/




/*
#include<iostream>
#include<algorithm>
#include<vector>

using namespace std;

int main(void) {
	int n;
	cin >> n;
	vector<int> arr(n, 0);
	vector<int> dp(n, 0);
	for (int i = 0; i < n; i++) {
		cin >> arr[i];
	}

	dp.at(0) = arr.at(0);
	int maxV = arr.at(0);
	for (int i = 1; i < n; i++) {
		dp[i] = max(dp.at(i - 1) + arr[i], arr[i]);
		maxV= max(maxV,dp[i]);
	}
	cout << maxV;
	return 0;
}
2800
24ms
*/
