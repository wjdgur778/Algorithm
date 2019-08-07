#include<iostream>
#include<algorithm>
using namespace std;
//자두나무 
//어려워~~~~~~~~~~~~~~~~
//dynamic programming

int t;
int w;

int tree[1001];
int dp[1001][32] = { 0, };//[위치][움직일수있는 횟수]
int ans = 0;
int solution() {

	for (int i = 1; i <= t; i++) {
		for (int j = 0; j <= w; j++) {

			if (tree[i] == 1) {
				if (j % 2 == 0) {//w가 짝수 일때 (내위치 1)
					dp[i][j] = max(dp[i - 1][j], dp[i - 1][j + 1]) + 1;
				}
				else {//w가 홀수일때 (내위치 2)
					dp[i][j] = max(dp[i - 1][j], dp[i - 1][j + 1]);
				}
			}
			else if (tree[i] == 2) {
				if (j % 2 == 0) {//w가 짝수 일때 (내위치 1)
					dp[i][j] = max(dp[i - 1][j], dp[i - 1][j + 1]);
				}
				else {//w가 홀수일때 (내위치 2)
					dp[i][j] = max(dp[i - 1][j], dp[i - 1][j + 1]) + 1;
				}
			}
		}
	}//자두나무가 1 일때, 가만히 있는경우 +1 혹은 움직이고 +0
	 //자두나무가 2 일때, 가만히 있는경우 +0 혹은 움직이고 +1

	for (int i = 0; i <= w; i++) {
		ans = max(ans, dp[t][i]);
	}
	return 0;
}



int main()
{
	cin >> t;
	cin >> w;
	for (int i = 1; i <= t; i++) {
		cin >> tree[i];
	}
	solution();
	cout << ans;

	return 0;
}