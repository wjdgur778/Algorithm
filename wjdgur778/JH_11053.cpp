#include<iostream>
#include<algorithm>
using namespace std;


int n;
int arr[1001];
int dp[1001] = { 0, };
int ans = 0;
void solution()
{
	for (int i = 1; i < n; i++) {
		int tmp = 0;
		for (int j = 1; j <= i; j++) {
			if (arr[i] > arr[i - j]) {
				if (dp[i - j] > tmp) {
					tmp = dp[i - j];
					dp[i] = tmp+1;
				}
			}
		}
	}
	for (int i = 0; i < n; i++) {
		if (dp[i] > ans) {
			ans = dp[i];
		}
	}
	cout << ans;
}

int main()
{
	cin >> n;
	for (int i = 0; i < n; i++) {
		cin >> arr[i];
	}
	fill_n(dp, 1001, 1);
	solution();

	return 0;

}