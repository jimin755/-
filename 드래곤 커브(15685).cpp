#include<iostream>
#include<vector>

using namespace std;

void spin(vector<pair<int, int>> &curve) {
	int dx = curve[curve.size() - 1].first;
	int dy = curve[curve.size() - 1].second;
	int sx = 0 - dx, sy = 0 - dy; // 상대 좌표 움직임 정도
	int mx = 0, my = 0; // 상대 좌표
	int c_size = curve.size();
	for(int i = c_size - 2; i >= 0; i--) {
		mx = curve[i].first + sx;
		my = curve[i].second + sy;
		curve.push_back(make_pair(-my - sx, mx - sy));
	}
}

int main(void) {
	int n;
	cin >> n;
	int box = 0;

	vector<vector<pair<int, int>>> curve(n, vector<pair<int, int>>(0, make_pair(0, 0)));
	vector<vector<pair<bool, bool>>> board(1001, vector<pair<bool, bool>>(1001, make_pair(false, false)));

	int x = 0, y = 0, d = 0, g = 0;
	for (int i = 0; i < n; i++) {
		cin >> x >> y >> d >> g;
		curve[i].push_back(make_pair(x, y));
		if (d == 0) {
			curve[i].push_back(make_pair(x + 1, y));
		}
		else if (d == 1) {
			curve[i].push_back(make_pair(x, y-1));
		}
		else if (d == 2) {
			curve[i].push_back(make_pair(x-1, y));
		}
		else if(d==3){
			curve[i].push_back(make_pair(x, y+1));
		}
		for (int t = 1; t <= g; t++) {
			spin(curve[i]);
		}
		for (int z = 0; z < curve[i].size(); z++) {
			board[curve[i][z].second + 500][curve[i][z].first + 500].first = true;
		}
	}

	for (int y = 0; y < curve.size(); y++) {
		for (int x = 0; x < curve[y].size(); x++) {
			bool a = board[curve[y][x].second + 500][curve[y][x].first + 500].first;
			bool b = board[curve[y][x].second + 501][curve[y][x].first + 500].first;
			bool c = board[curve[y][x].second + 500][curve[y][x].first + 501].first;
			bool d = board[curve[y][x].second + 501][curve[y][x].first + 501].first;
			bool ta = board[curve[y][x].second + 500][curve[y][x].first + 500].second;
			if (ta==false && a == true && b == true && c == true && d == true) {
				box++;
				board[curve[y][x].second + 500][curve[y][x].first + 500].second = true;
			}
		}
	}
	cout << box << endl;
	return 0;
}