#include<iostream>
#include<vector>
#include<string>
#include<algorithm>
#include<cstring>
#include<queue>
using namespace std;
bool primeCheck[10000];

void pri() {
	for (int i = 0; i < 10001; i++) {
		primeCheck[i] = true;
	}
	for (int i = 3; i < 10000; i++) {
		for (int j = 2; j < i; j++) {
			if (i % j == 0) {
				primeCheck[i] = false;
				break;
			}
		}
	}
} // 소수 확인 및 저장

void BFS(int n ,vector<int> start ,int *&visit) {
	queue<int> q;
	q.push(start[n]);
	for (int i = 1000; i < 10000; i++) {
		visit[i] = -1;
	}

	visit[start[n]] = 0;
	while (!q.empty()) {
		string temp;
		int num = q.front();
		q.pop();
		// 맨 앞자리부터 하나하나 탐색을 해서 검사
		for (int i = 0; i < 4; i++) {
			temp = to_string(num);
			for (int j = 0; j < 10; j++) {
				temp[i] = j + '0';
				int next = atoi(temp.c_str());
				if (next >= 1000 && primeCheck[next] == true && visit[next] == -1) {
					visit[next] = visit[num] + 1;
					q.push(next);
				}
			}
		} // visit 가 -1이면 방문을 안한것 전 노드 방문횟수에 쌓아서 최단 방문횟수 탐색
	}
}//BFS로 탐색

int main(void) {
	int n , a;
	cin >> n;
	vector<int> start, result; // 시작값과 결과여야 하는 값 저장
	queue<int> q; // 큐 
	int *visit = new int[10000]; // 방문
	pri();
	for (int i = 0; i<n; i++) {
		cin >> a;
		start.push_back(a);
		cin >> a;
		result.push_back(a);
	}

	for (int i = 0; i < n; i++) {
		BFS(i, start, visit);
		if (visit[result[i]] != -1) {
			cout << visit[result[i]] << endl;
		}
		else {
			cout << -1 << endl;
		}
	}

	return 0;
}
