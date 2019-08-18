#include<iostream>
#include<algorithm>
using namespace std;
//¿¬¼ÓÇÕ

int dp[100000];
int arr[100000];
int n;

void solution()
{
	int ans=0;
	for (int i = 1; i < n; i++) {
		
		if (dp[i - 1]+arr[i] < arr[i]) {
			dp[i] = arr[i];
		}
		else {
			dp[i] = dp[i - 1] + arr[i];
		}

	}
	for (int i = 0; i < n; i++) {
		if (dp[i] > ans) {
			ans = dp[i];
		}
	}
	cout << ans;
}

int main() {

	cin >> n;
	for (int i = 0; i < n; i++) {
		cin >> arr[i];
	}
	dp[0] = arr[0];
	solution();
	return 0;
}