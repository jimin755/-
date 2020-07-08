#include<iostream>
#include<string>

using namespace std;

// 0을제외하고 보면 0에 영향을 줄수 있는것은 1번 버튼
// 1버튼을 누르고 나면 1번에 영향을 줄수 있는 것은 2번 버튼 
// 그리고 1번후 2번을 누른 것과 2번을 누른후 1번을 누른것과 결과가 같음
// 이런 공식들을 생각해서 만든 것

//xor 생각해보기
string button(string temp ,int index) {
	for (int i = index - 1; i <= index + 1; i++) {
		if (i >= 0 && i < temp.length()) {
			temp[i] = (1 - (temp[i]-'0'))+'0'; 
			// string 형으로 받아서 생긴 계산방식
		}
	}
	return temp;
} // 버튼을 누르는 경우의 수

bool DFS(string start , string cEnd ,int &result) {
	int counter = 0;
	for (int i = 1; i < start.length(); i++) {
		if (start[i - 1] != cEnd[i - 1]) {
			start = button(start, i);
			counter++;
		}
	} // 0을 누른경우와 안누른 경우는 main에서 처리하고 
	// 0을 신경안쓰면 0번에 영향을 줄수 있는 버튼은 1번 버튼 따라서 
	//목표 문자열의 i-1번째 문자와 같지않은 경우에만 i번째 버튼을 눌러준다
	result = counter;
	for (int i = 0; i < start.length(); i++) {
		if (start[i] != cEnd[i]) {
			return false;
		}
	} // 같은지 확인하고 참거짓 반환
	return true;
}

int main(void) {
	int n, result = -1;
	cin >> n;
	string start, cEnd;
	cin >> start >> cEnd;

	if (DFS(start, cEnd, result)) {
		cout << result << endl;
	}// 0을 안누르는 경우
	else {
		start = button(start, 0);
		if (DFS(start, cEnd, result)) {
			cout << result+1 << endl;
		} //0을 누르고 시작한 경우
		else {
			cout << -1 << endl;
		}
	}
	return 0;
}
