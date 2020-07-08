#include<iostream>
#include<string>
#include <algorithm>

using namespace std;

// 주어진 식을 10의 거듭제곱을 붙여서 모두 더해주는 것
// 우리 문제 예시로는
//2
//GCF
//ACDEB 
// 이렇게있으면 
// GCF -> 100G 10C 1F ACDEB -> 10000A 1000C 100D 10E 1B 이렇게 숫자를 부여해서
// 다 더하면 A -> 10000 B -> 1 C-> 1010 D ->100 E->10 F ->1 G->100 이렇게 되고 
// 큰 값부터 9 8 7 이런식으로 값을 부여해서 다더하면 가장 큰값이 나온다.


int power(int n) {
	int ten = 1;
	for (int i = 0; i < n; i++) {
		ten *= 10;
	}
	return ten;
} // 10의 n승을 구하는 함수

int main(void) {

	long long al[26] = { 0 }; // 알파벳 0 - >A 1 ->B 2->C이런식으로 지정하고 각 알파벳의 값을 저장할 배열
	int n;
	long long result = 0;
	cin >> n;
	string temp;

	for (int i = 0; i < n; i++) {
		cin >> temp;
		for (int j = 0; j < temp.length(); j++) {
			al[temp[j] - 'A'] += power(temp.length() - 1 - j);
		}
	} // 입력받고 각 알파벳의 값을 al에 저장해준다.

	int counter = 9;

	for (int i = 0; i < 26; i++) {
		if ((*max_element(al, al + 26)) != 0) {
			result += (*max_element(al, al + 26)) * counter;
			counter--;
			(*max_element(al, al + 26)) = 0;
		}
		else{
			break;
		}
	} // max_element를 사용 배열에서 가장 큰값부터 9 8 7 차례대로 값을 곱해서 더해준다.
	cout << result << endl;
	return 0;
}
