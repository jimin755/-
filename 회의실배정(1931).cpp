#include<iostream>
#include<vector>
#include<algorithm>

using namespace std;
// 겹치면 둘중 더 나은 대안을 선택
// 안겹치면 회의 시간표에 추가
int main(void) {
	int n, cfStart, cfEnd, cursor = 0;
	cin >> n;
	vector<pair<int, int>> conference; //회의 신청 
	vector<pair<int, int>> timeTable; // 회의 시간표
	for (int i = 0; i < n; i++) {
		cin >> cfStart >> cfEnd;
		conference.push_back(make_pair(cfStart, cfEnd));
	}
	sort(conference.begin(), conference.end()); // 회의 시작 시간으로 sort
	timeTable.push_back(make_pair(conference[0].first, conference[0].second));
	for (int i = 1; i < conference.size(); i++) {
		cfStart = conference[i].first;
		cfEnd = conference[i].second;

		if (timeTable[cursor].second > cfStart) {
			if (timeTable[cursor].second > cfEnd) {
				timeTable[cursor].first = cfStart;
				timeTable[cursor].second = cfEnd;
			} // 회의 시간이 겹치는 경우 더 나은 선택으로 교체
		} 
		else {
			timeTable.push_back(make_pair(cfStart, cfEnd));
			cursor++;
		} // 겹치지 않는 경우 회의시간표에 추가
	}
	cout << timeTable.size() << endl;
	return 0;
}
