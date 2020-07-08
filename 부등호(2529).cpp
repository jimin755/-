#include<iostream>
#include<cstdlib>
#include<algorithm>

// 가장 큰 값을 구하는 케이스 
// 가장 작음 값을 구하는 케이스로 나눈다음
// 순열 함수인 next_permutation을 사용해서 값을 구한다
using namespace std;

bool checkOp(char op, int n1, int n2) {
	if (op == '>') {
		return(n1 > n2);
	}
	else {
		return(n1 < n2);
	}
} // 대소 관계가 타당한지 구하는 함수

char *permutation(char* op, char* numCase ,int n ,bool c) { // max 구하는거면c == true 
	char * arr = new char[n];
	long long min = 9999999999, max = 0, temp = 0;
	do
	{
		bool check = true;
		for (int i = 0; i < n; i++) {
			if (i == 0) {
				check = checkOp(op[i], numCase[0], numCase[1]);
				if (check == false) {
					break;
				}
			}
			else {
				check = checkOp(op[i], numCase[i], numCase[i + 1]);
				if (check == false) {
					break;
				}
			}
		}

		if (check == true) {
			temp = atol(numCase);
			if (c == true) {
				if (max < temp) { // 기존의 max값보다 크면 
					max = temp;
					for (int i = 0; i <= n; i++) {
						arr[i] = numCase[i];
					} //저장
				}
			}
			else {
				if (min > temp) {
					min = temp;
					for (int i = 0; i <= n; i++) {
						arr[i] = numCase[i];
					}
				}
			}
		}
	} while (next_permutation(numCase, numCase + (n + 1)));
	return arr;
}

int main(void) {

	int n;
	cin >> n;

	long long min = 9999999999, max = 0, temp = 0;
	char *op = new char[n];
	char *bigCase = new char[n + 1]; // 큰 케이스의 숫자 범위내의 숫자를 저장할 배열
	char *smallCase = new char[n + 1]; // 작은 케이스의 숫자 범위 내의 숫자를 저장할 배열
	char *big = new char[n + 1]; //여러케이스중 가장 큰 케이스의 값을 저장할 배열
	char *small = new char[n + 1]; // 여래케이스중 가장 작은 케이스의 값을 저장할 배열

	for (int i = 0; i < n; i++) {
		cin >> op[i];
	}
	
	for (int i = 0; i <= n; i++) {
		smallCase[i] = '0'+i;
		bigCase[i] = '0' + (9 - n + i);
	}
	big = permutation(op, bigCase, n, true);
	small = permutation(op, smallCase, n, false);
	for (int i = 0; i <= n; i++) {
		cout << big[i] ;
	}
	cout << endl;
	for (int i = 0; i <= n; i++) {
		cout << small[i];
	}
	return 0;
}
