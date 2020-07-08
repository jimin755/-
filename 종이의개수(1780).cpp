#include<iostream>
#include<algorithm>
#include<vector>

const int MAX = 2187;
using namespace std;
int n, zero, one , mOne; // 사이즈와 카운트할 변수
int paper[MAX][MAX]; // 번호저장 배열
 //전역변수로하면 시간을 절약가능 

void cut(int y, int x, int size) {
	bool mOn = true, on = true, ze = true;
	for (int i = y; i < y+size; i++) {
		for (int j = x; j < x+size; j++) {
			if (paper[i][j] == -1) {
				on = false;
				ze = false;
			}
			else if (paper[i][j] == 0) {
				mOn = false;
				on = false;
			}
			else if (paper[i][j] = 1) {
				ze = false;
				mOn = false;
			}
			if (on == false && ze == false && mOn == false) {
				break;
			}
		}
		if (on == false && ze == false && mOn == false) {
			break;
		}
	} //하나의 구역이 다 같은수인지 아닌지 검사
	if (on == false && ze == false && mOne == false && size == 3) {
		for (int i = y; i < y + 3; i++) {
			for (int j = x; j < x + 3; j++) {
				if (paper[i][j] == 0) {
					zero++;
				}
				else if (paper[i][j] == 1) {
					one++;
				}
				else {
					mOne++;
				}
			}
		}
		return;
	} // size 가 3이면서 안에 요소들이 다를때 
	else if (on) {
		one++;
		return;
	} // 구역의 요소가 1로 같을때
	else if (ze) {
		zero++;
		return;
	}
	else if (mOn) {
		mOne++;
		return;
	}
	else {
		size = size / 3;
		int x1 = x + size, y1 = y + size, x2 = x + (2 * size), y2 = y + (2 * size);
		cut(y, x, size);
		cut(y1, x, size);
		cut(y2, x, size);

		cut(y, x1, size);
		cut(y1, x1, size);
		cut(y2, x1, size);

		cut(y, x2, size);
		cut(y1, x2, size);
		cut(y2, x2, size);
		return;
	} //재귀
}

int main(void) {
	ios_base::sync_with_stdio(false);
	cin.tie(0);
	cin >> n;
	bool c = true;
	for (int i = 0; i < n; i++) {
		for (int j = 0; j < n; j++) {
			cin >> paper[i][j];
		}
	}
	cut(0, 0, n);
	cout << mOne << endl << zero << endl << one << endl;
	return 0;
}
