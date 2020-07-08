#include<iostream>
#include<vector>
#include<algorithm>

using namespace std;
bool cmp(pair<int, int> a, pair<int, int>b) {
	return a.second < b.second;
}

int main(void) {
	int n,tem;
	cin >> n;
	vector<pair<int,int>> num , people;
	vector<int> result;
	for (int i = 0; i < n; i++) {
		cin >> tem;
		num.push_back(make_pair(tem, i + 1));
		people.push_back(make_pair(0, i + 1));
	}
	sort(num.begin(), num.end());
	tem = 0;
	int en = 0;
	while (num.size()>0) {
		for (int i = 0; i < num.size(); i++) {
			if (num[i].first > tem) {
				en = i;
				break;
			}
			else {
				en = num.size();
			}
		}
		sort(num.begin(), num.begin() + en,cmp);
		for (int i = 0; i < num.size(); i++) {
			if (people[num[i].second - 1].first == num[i].first) {
				result.push_back(num[i].second);
				for (int j = 0; j < num[i].second;j++) {
					people[j].first++;
				}
				num.erase(num.begin() + i);
				break;
			}
		}
		tem++;
	}
	for (int i = 0; i < n; i++) {
		cout << result[i] << ' ';
	}
	return 0;
}
