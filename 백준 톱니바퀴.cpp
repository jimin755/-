#include<iostream>
#include<vector>
#include<cmath>

using namespace std;

void clock(vector<int> &arr) {
	int temp = arr[7]; 
	for (int i = 6; i >= 0; i--) {
		arr[i + 1] = arr[i];
	}
	arr[0] = temp;
}
void nonclock(vector<int> &arr) {
	int temp = arr[0];
	for (int i = 0; i < 7; i++) {
		arr[i] = arr[i + 1];
	}
	arr[7] = temp;
}

int main(void) {
	vector<vector<int>> one(4, vector<int>(8, 0));
	vector<pair<int, int>> moving;
	string strt;
	for (int i = 0; i < 4; i++)
	{
		cin >> strt;
		for (int j = 0; j < 8; j++) {
			one[i][j] = strt[j] - '0';
		}
	}
	int n, a, b;
	cin >> n;

	for (int i = 0; i < n; i++) {
		cin >> a >> b;
		if (a == 1) {
			if (b == 1) {
				for (int t = 0; t < 4; t++) {
					int tem = one[t][2];
					if (t % 2 == 0) {
						clock(one[t]);
					}
					else {
						nonclock(one[t]);
					}
					if (t==3 || tem == one[t + 1][6]) {
						break;
					}
				}
			} // 시계방향
			else {
				for (int t = 0; t < 4; t++) {
					int tem = one[t][2];
					if (t % 2 == 0) {
						nonclock(one[t]);
					}
					else {
						clock(one[t]);
					}
					if (t==3 || tem == one[t + 1][6]) {
						break;
					}
				}
			}
		}
		else if (a == 2) {
			if (b == 1) {
				if (one[0][2] != one[1][6]) {
					nonclock(one[0]);
				}
				for (int t = 1; t < 4; t++) {
					int tem = one[t][2];
					if (t % 2 == 1) {
						clock(one[t]);
					}
					else {
						nonclock(one[t]);
					}
					if (t == 3||tem == one[t + 1][6]) {
						break;
					}
				}
			}
			else {
				if (one[0][2] != one[1][6]) {
					clock(one[0]);
				}
				for (int t = 1; t < 4; t++) {
					int tem = one[t][2];
					if (t % 2 == 1) {
						nonclock(one[t]);
					}
					else {
						clock(one[t]);
					}
					if (t==3 || tem == one[t + 1][6]) {
						break;
					}
				}
			}
		}
		else if (a == 3) {
			if (b == 1) {
				if (one[3][6] != one[2][2]) {
					nonclock(one[3]);
				}
				for (int t = 2; t >= 0; t--) {
					int tem = one[t][6];
					if (t % 2 == 0) {
						clock(one[t]);
					}
					else {
						nonclock(one[t]);
					}
					if (t==0 || tem == one[t - 1][2]) {
						break;
					}
				}
				
			}
			else {
				if (one[3][6] != one[2][2]) {
					clock(one[3]);
				}
				for (int t = 2; t >= 0; t--) {
					int tem = one[t][6];
					if (t % 2 == 0) {
						nonclock(one[t]);
					}
					else {
						clock(one[t]);
					}
					if (t==0||tem == one[t - 1][2]) {
						break;
					}
				}
			}
		}
		else if (a == 4) {
			if (b == 1) {
				for (int t = 3; t >= 0; t--) {
					int tem = one[t][6];
					if (t % 2 == 1) {
						clock(one[t]);
					}
					else {
						nonclock(one[t]);
					}
					if (t==0||tem == one[t - 1][2]) {
						break;
					}
				}
			}
			else {
				for (int t = 3; t >= 0; t--) {
					int tem = one[t][6];
					if (t % 2 == 1) {
						nonclock(one[t]);
					}
					else {
						clock(one[t]);
					}
					if (t==0||tem == one[t - 1][2]) {
						break;
					}
				}
			}
		}
	}
	float score = 0;
	for (int i = 0; i < 4; i++) {
		if (one[i][0] == 1) {
			score += pow(2, i);
		}
	}
	cout << int(score) << endl;
	return 0;
}