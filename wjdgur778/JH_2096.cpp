#include<iostream>
#include<algorithm>
using namespace std;
//내려가기
//dynamic programming

int n;
int m_map[3];//최댓값을 위한 map
int n_map[3];//최솟값을 위한 map
int m_dp[3];//최댓값을 위한 dp
int n_dp[3];//최솟값을 위한 dp
int ans;
void solution() {

	int tmp;

	if (n == 1) {
		tmp = max(m_map[0], m_map[1]);
		ans = max(tmp, m_map[2]);
		cout << ans << " ";

		tmp = min(n_map[0], n_map[1]);
		ans = min(tmp, n_map[2]);
		cout << ans;
		return;
	}//n이 1일때 예외처리
		

	for (int i = 1; i < n; i++) {
		cin >> m_dp[0] >> m_dp[1] >> m_dp[2];
		n_dp[0] = m_dp[0]; n_dp[1] = m_dp[1]; n_dp[2] = m_dp[2];

		m_dp[0] = max(m_map[0], m_map[1])+m_dp[0];
		tmp = max(m_map[0], m_map[1]);
		m_dp[1] = max(tmp, m_map[2])+m_dp[1];
		m_dp[2] = max(m_map[1], m_map[2]) + m_dp[2];

		n_dp[0] = min(n_map[0], n_map[1]) + n_dp[0];
		tmp = min(n_map[0], n_map[1]);
		n_dp[1] = min(tmp, n_map[2]) + n_dp[1];
		n_dp[2] = min(n_map[1], n_map[2]) + n_dp[2];

		m_map[0] = m_dp[0];
		m_map[1] = m_dp[1];
		m_map[2] = m_dp[2];

		n_map[0] = n_dp[0];
		n_map[1] = n_dp[1];
		n_map[2] = n_dp[2];
	}//
	
	tmp = max(m_dp[0], m_dp[1]);
	ans = max(tmp, m_dp[2]);
	cout << ans<<" ";

	tmp = min(n_dp[0],n_dp[1]);
	ans = min(tmp, n_dp[2]);
	cout << ans;
}
//map -> dp
int main() {
	
	cin >> n;
	cin >> m_map[0] >> m_map[1] >> m_map[2];
	n_map[0] = m_map[0]; n_map[1] = m_map[1]; n_map[2] = m_map[2];
	solution();

	return 0;
}