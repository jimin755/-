#define _CRT_SECURE_NO_WARNINGS
#include <vector>
#include <iostream>
#include <algorithm>
using namespace std;
//이진 탐색 대상을 공유기 개수나 집을 대상으로 하는 것이아니라.
//
int main(void) {
	int n, m, tem;
	scanf("%d%d", &n, &m);
	vector<int> house;
	for (int i = 0; i < n; i++) {
		scanf("%d", &tem);
		house.push_back(tem);
	}
	sort(house.begin(), house.end());

	int minCase = 1; // 이진 탐색시 start
	int maxCase = house[n - 1] - house[0]; // 이진탐색 end
	int mid = (maxCase + minCase) / 2; // mid
	// 공유기 설치 개수를 이진탐색 대상으로 설정
	int counter; // 공유기 설치 개수
	int result = 0; // 결과값 저장

	while (minCase<=maxCase) {
		mid = (maxCase + minCase) / 2;
		int now = house[0]; 
		// 마지막으로 공유기를 설치한 지점 거리를 측정하기위해 만듬
		counter = 1;//맨처음 집에는 무조건 공유기를 설치해놓고 시작하므로 1부터시작

		for (int i = 1; i < n; i++) {
			if (house[i] - now >= mid) {
				counter++;
				now = house[i];
			}
		}// 공유기를 mid의 수치만큼 거리를 설정하고 공유기 설치

		//공유기 설치개수 비교
		if (counter < m) {
			maxCase = mid - 1;
		} 
		// 공유기 설치 개수와 입력 받은 공유기 개수를 비교 
		//작으면 범위를 앞으로 줄이고
		else if(counter>m) {
			minCase = mid + 1;
			tem = mid;
		}// 크면 범위를 뒤로 줄인다.
		else{
			result = mid;
			minCase = mid + 1;
		} // 같으면 result에 저장하고 범위를 뒤로 줄여 더 탐색해본다.
	}
	if (result == 0) {
		cout << tem << endl;
	} 
	// 딱떨어지게 설치 개수가 나오지 않는다면 마지막 이진탐색 mid값을 결과값으로 제출
	else {
        cout << result << endl;
	}
	
	return 0;
}

