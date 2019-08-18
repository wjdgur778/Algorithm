#include<iostream>
#include<algorithm>
using namespace std;
//가장 큰 증가 부분 수열
int n;
int arr[1002];
int dp[1002];
int m = 0;
void solution() {

	/* 1 100 2 50 60 3 5 6 7 8 */
	// 1 101 3 53 113
	for (int i = 1; i < n; i++) {
		m = 0;
		for (int j = 1; j <= i; j++) {
			if (arr[i] > arr[i - j]) {
				if (m < dp[i - j]) {
					m = dp[i - j];
				}
			}
			dp[i] = m + arr[i];
		}

	}
		sort(dp, dp + n);
		cout << dp[n - 1];
}

int main()
{
	cin >> n;
	for (int i = 0; i < n; i++) {
		cin >> arr[i];
		dp[i] = arr[i];
	}

	solution();
	return 0;
}