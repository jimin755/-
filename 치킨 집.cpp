#include<iostream>
#include<vector>
#include<algorithm>
#define MAX(a,b) (((a)>(b)) ? (a) : (b))
#define MIN(a,b) (((a)<(b)) ? (a) : (b))
using namespace std;

void dis(vector<pair<int, int>> house, vector<vector<int>>& distance, int y, int x ,int n) {
	int dis = 0;
	for (int i = 0; i < house.size(); i++) {
		dis = (MAX(y, house[i].first) - MIN(y, house[i].first)) + (MAX(x, house[i].second) - MIN(x, house[i].second));
		if (distance[house[i].first][house[i].second] == 0) {
			distance[house[i].first][house[i].second] = dis;
		}
        else if (distance[house[i].first][house[i].second] > dis) {
			distance[house[i].first][house[i].second] = dis;
		}
	}
}

int dis_sum(vector<vector<int>>& distance, int n) {
	int sum = 0;
	for (int y = 0; y < n; y++) {
		for (int x = 0; x < n; x++) {
			sum += distance[y][x];
		}
	}
	return sum;
}

int main(void) {
	int n, m, tem, min = 99999999999;
	cin >> n >> m;

	vector<vector<int>> distance(n, vector<int>(n, 0));
	vector<pair<int, int>> chick;
	vector<pair<int, int>> house;
	
	for (int y = 0; y < n; y++) {
		for (int x = 0; x < n; x++) {
			cin >> tem;
			if (tem == 2) {
				chick.push_back(make_pair(y, x));
			}
			else if (tem == 1) {
				house.push_back(make_pair(y, x));
			}
		}
	}
	vector<int> combi, ind;
	for (int i = 0; i < chick.size(); i++) {
		combi.push_back(i);
	}
	for (int i = 0; i < m; i++) {
		ind.push_back(1);
	}
	for (int i = 0; i < chick.size() - m; i++) {
		ind.push_back(0);
	}
	sort(ind.begin(), ind.end());
	do {
		// Ãâ·Â
		for (int i = 0; i < ind.size(); i++) {
			if (ind[i] == 1) {
				dis(house, distance, chick[combi[i]].first, chick[combi[i]].second, n);
			}
		}
		int sum = dis_sum(distance, n);
		if (min > sum) {
			min = sum;
		}
		vector<vector<int>> distance1(n, vector<int>(n, 0));
		distance = distance1;
	} while (next_permutation(ind.begin(), ind.end()));

	cout << min << endl;
	return 0;
}