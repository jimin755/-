#include<iostream>
#include<vector>

using namespace std;

int one = 0, zero = 0;
int main(void) {
    int n = 0, max = 0;

    cin >> n;
    int* arr = new int[n];
    vector<pair<int, int>> pibona;
    pibona.push_back(make_pair(1, 0)); // 0
    pibona.push_back(make_pair(0, 1)); // 1
    pibona.push_back(make_pair(1, 1)); // 2 
    pibona.push_back(make_pair(1, 2)); // 3
    pibona.push_back(make_pair(2, 3)); // 4

    for (int i = 0; i < n; i++) {
        cin >> arr[i];
        if (max < arr[i])
        {
            max = arr[i];
        }
    }

    for (int i = 5; i <= max; i++) {
        int fir = pibona[i - 2].first + pibona[i - 1].first;
        int sec = pibona[i - 2].second + pibona[i - 1].second;
        pibona.push_back(make_pair(fir, sec));
    }

    for (int i = 0; i < n; i++) {
        cout << pibona[arr[i]].first << " " << pibona[arr[i]].second << endl;
    }
    
	return 0;
}
