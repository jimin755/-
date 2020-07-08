#include<iostream>

//score[k][n] 
// score[k][n] =score[k-1][n] + score[k][n-1]
using namespace std;
int main(void) {

	int n = 0, k = 0, result = 0;;
	cin >> n >> k;
	if (n > 0 && n < 201 && k>0 && k < 201) {
		int ** score = new int*[k + 1];

		for (int i = 0; i < k + 1; i++) {
			score[i] = new int[n + 1];
		}

		for (int i = 0; i < k + 1; i++) {
			for (int j = 0; j < n + 1; j++) {
				score[i][j] = 1;
			}
		}

		for (int k1 = 2; k1 < k + 1; k1++) {
			for (int n1 = 1; n1 < n + 1; n1++) {
				score[k1][n1] = score[k1 - 1][n1] + score[k1][n1 - 1];
				if (score[k1][n1] > 1000000000) {
					score[k1][n1] = score[k1][n1] % 1000000000;
				}
			}
		}
		////score[k][n] 
    // score[k][n] =score[k-1][n] + score[k][n-1] 
		cout << score[k][n] << endl;
	}

	return 0;
}
