#include<iostream>
#include<vector>
#include<cmath>

using namespace std;
int zx[] = { 0, 1,0,1 };
int zy[] = { 0, 0,1,1 };
//오른쪽 아래 대각선

void aSearch(int xStart,int yStart,int &cursor , int size ,int r,int c, bool &b ) {
	if (b == true) {
		if (size == 2) {
			for (int i = 0; i < 4; i++) {
				if (yStart + zy[i] == r && xStart + zx[i] == c) {
					b = false;
					return;
				} // 해당하는 좌표를 찾았으면 b를 false으로 만들고 리턴 
				cursor++;
			}
		}
		else {
			size = size / 2;
			int sum = size * size; // 2^(n-1) = size 이고 size * size는 그 분할 구역의 원소 갯수이다
			// 찾은 좌표가 존재하지 않는 사분면은 탐색하지 않고 그냥 cursor에 그 분할 구역 원소 갯수만 더해준다.
			if (xStart + size > c && yStart + size > r) {
				aSearch(xStart, yStart, cursor, size, r, c, b);
			}
			else if (b == true) {
				cursor = cursor + sum;
			}
			if (xStart + (2 * size) > c && yStart + size > r) {
				aSearch(xStart + size, yStart, cursor, size, r, c, b);
			}
			else if (b == true) {
				cursor = cursor + sum;
			}
			if (xStart + size > c && yStart + (2 * size) > r) {
				aSearch(xStart, yStart + size, cursor, size, r, c, b);
			}
			else if(b==true){
				cursor = cursor + sum;
			}
			if (xStart + (2 * size) > c && yStart + (2 * size) > r) {
				aSearch(xStart + size, yStart + size, cursor, size, r, c, b);
			}
			else if (b == true) {
				cursor = cursor + sum;
			}
		}
	}
	else {
		return;
	}
}

int main(void) {
	int n, r, c, cursor = 0;
	bool b = true; // 찾는 수를 찾은 이후에는 연산이 적용되지않게 하기위한 참거짓 변수
	cin >> n >> r >> c;
	int size = pow(2, n);
	aSearch(0, 0, cursor, size, r, c, b);
	cout <<cursor << endl;
	return 0;
}
