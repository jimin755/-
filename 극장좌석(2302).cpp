#include<iostream>

//앉는 경우 경우의 수 점화식
// sitCase[i] = sitCase[i-1]+sitCase[i-1] (i>=2)

using namespace std;
int main(void)
{
	int n = 0, m = 0;
	cin >> n >> m;

	int *vip = new int[m]; // vip 입력받을 곳
	int *sitCase = new int[n+1]; // 좌석수당 경우의 수 저장할 배열
	int *gap = new int[m + 1]; // 각 vip좌석이 아닌 사이사이의 길이를 저장할 배열

	int gapsize = 0 ,result = 0;
	
	if (n > 0 && n <= 40 && m >= 0 && m <= n) { // 조건 걸어둠
		//첫째 줄에는 좌석의 개수 N이 입력된다. N은 1 이상 40 이하이다. 
		//둘째 줄에는 고정석의 개수 M이 입력된다. M은 0 이상 N 이하이다. 
		sitCase[0] = 1;
		sitCase[1] = 1; 

		for (int i = 2; i < n + 1; i++) {
			sitCase[i] = sitCase[i - 1] + sitCase[i - 2];
		} // 앉는 경우의수 미리 다 계산 해놓음
		
		if (m == 0) {
			cout << sitCase[n] << endl;
			return 0;
		} // vip좌석이 없는 경우 

		for (int i = 0; i < m; i++) {
			cin >> vip[i];
			if (i == 0) {
				gap[gapsize] = vip[i] - 1;
				gapsize++;
				if (m==1) {
					gap[gapsize] = n - vip[i];
					gapsize++;
				} // vip좌석이 한자리일 경우 계산
			}
			else if (i == (m - 1)) {
				gap[gapsize] = vip[i] - vip[i - 1] - 1;
				gapsize++;
				gap[gapsize] = n - vip[i];
				gapsize++;
			} // vip 마지막 좌석에서의 gap 계산 해당 좌석과 그전 좌석사이 gap과
			//vip 마지막좌석과 끝과의 gap을 저장
			else {
				gap[gapsize] = vip[i] - vip[i - 1] - 1;
				gapsize++;
			} // vip좌석들 사이gap 저장
		} 

		for (int i = 0; i < gapsize; i++) {
			if (i == 0) {
				result = sitCase[gap[0]];
			}
			else {
				result *= sitCase[gap[i]];
			}
		} // gap은 즉 vip가 아닌 붙어있는 좌석의 부분 집합이고 
		// 그것을 기존에 계산해둔 앉는 경우의 수를 이용하여 계산

		cout << result << endl;
	}
	return 0;
}
