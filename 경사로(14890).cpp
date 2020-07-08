#include<iostream>
#include<vector>

using namespace std;
/*
Á¤´ä
*/

bool ch_road(vector<int> arr, int l) {
	int len = 1;
	vector<bool> tt(arr.size(), true);
	for (int i = 1; i < arr.size(); i++) {
		if (arr[i - 1] == arr[i]) {
			continue;
		}
		else if ((arr[i - 1] - arr[i]) == -1) {
			if (i - l >= 0) {
				for (int t = i - 1; t >= i - l; t--) {
					if (arr[i - 1] != arr[t] || tt[t] == false) {
						return false;
					}
					tt[t] = false;
				}
			}
			else {
				return false;
			}

		}
		else if ((arr[i - 1] - arr[i]) == 1) {
			if (i + l-1 < arr.size()) {
				for (int t = i; t < i + l; t++) {
					if (arr[t] != arr[i] || tt[t] == false) {
						return false;
					}
					tt[t] = false;
				}
			}
			else {
				return false;
			}
		}
		else {
			return false;
		}
	}
	return true;
}

int main(void) {
	int n, l, ind = 0;
	cin >> n >> l;
	vector<vector<int>> street(n, vector<int>(n, 0));
	vector<vector<int>> street1(n, vector<int>(n, 0));
	for (int y = 0; y < n; y++) {
		for (int x = 0; x < n; x++) {
			cin >> street[y][x];
			street1[x][y] = street[y][x];
		}
	}
	for (int i = 0; i < n; i++) {
		if (ch_road(street[i], l)) {
			ind++;
		}
		if (ch_road(street1[i], l)) {
			ind++;
		}
	}
	cout << ind << endl;
	return 0;
}
