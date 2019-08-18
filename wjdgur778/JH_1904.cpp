#include<iostream>
using namespace std;

//01Å¸ÀÏ
//like fibonacci

int n;
int dp[1000001] = { 0 };
int solution(int n)
{
	if (n == 1) return dp[1];
	else {
		if (dp[n] == 0) {
			return  dp[n] = solution(n - 2)%15746 + solution(n - 1) % 15746;
		}
		else return dp[n]%15746;
	}
}
int main()
{
	cin >> n;
	dp[0] = 1;
	dp[1] = 1;
	solution(n);
	cout << dp[n]%15746;
	return 0;
}