#include<iostream>
#include<vector>
#include<algorithm>
using namespace std;
//정수 삼각형
//dynamic programming

vector<vector<int>> triangle;
vector<vector<int>> dp;

int n;

void solution() {
	
	for (int i = 0; i < n-1; i++) {
		for (int j = 0; j < triangle[i].size(); j++) {

			dp[i + 1][j] = max(dp[i + 1][j], dp[i][j] + triangle[i + 1][j]);
			dp[i + 1][j+1] = max(dp[i + 1][j+1], dp[i][j] + triangle[i + 1][j+1]);
		}
	}//dp라는 백터를 더 만들어서 메모이제이션을 하면서 최댓값을 구한다.

	sort(dp[n - 1].begin(), dp[n - 1].end());//최댓값이 들어있는 마지막줄에서 최대값을 찾기위해 소트
	cout << dp[n - 1][n - 1];//최댓값 출력
}

int main() {
	int a;
	cin >> n;
	triangle = vector<vector<int>>(n);
	dp = vector<vector<int>>(n);
	for (int i = 0; i < n; i++) {
		for (int j = 0; j < i+1; j++) {
			cin >> a;
			triangle[i].push_back(a);
			dp[i].push_back(a);
		}
	}//입력
	solution();
	
	return 0;
}