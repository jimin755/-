#include<iostream>
#include<algorithm>
#include<vector>

using namespace std;
// next_permutation으로 조합을 구현 
// 저것은 순열 차례대로 보여주는 함수이지만 
// 0과 1로 구성된 ind배열로 nCr을 구현 
// ind.size()가 n이고 r이 0의 갯수
// 이것으로 예시 케이스에서는 5개중에 1개일때 5개중 2개 5개증 3개 5개증 4개 5개중 5개인 경우를 더해서 각 값을 
// s와 비교해서 같은지 확인

int main(void) {
	int n, s, temp, result = 0 ,counter=0;
	cin >> n >> s;

	vector<int> num;
	vector<int> ind;

	for (int i = 0; i < n; i++) {
		cin >> temp;
		num.push_back(temp);
	}

	for (int i = 1; i <= n; i++) {
		if (i != 1) {
			ind.clear();
		}
		for (int k = 0; k < i; k++) {
			ind.push_back(0);
		}
		for (int k = 0; k < num.size() - i; k++) {
			ind.push_back(1);
		}
		// 순열함수로 조합을 구현하기위한 부분
		do
		{
			result = 0;
			for (int i = 0; i < ind.size(); i++) {
				if (ind[i] == 0) {
					result += num[i];
				}
			}
			
			if (result == s) {
				counter++;
			}

		} while (next_permutation(ind.begin(),ind.end())); 
	}
	cout << counter << endl;
	return 0;
}
