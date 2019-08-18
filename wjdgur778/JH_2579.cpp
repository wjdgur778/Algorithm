#include<iostream>
#include<algorithm>
using namespace std;

//��� ������
//dp
//�������� 3�� �Ѱ�ܾ� ������ �ȵ�
//������ �ִ밡 �ִ밡 �ƴҼ� �ִ�.
int n;
int arr[301];
int dp[301];
int a = 1;

//10 50 60 70 50 10 1

void solution() {
	for (int i = 3; i < n; i++) {
		dp[i] = max(arr[i] + arr[i - 1] + dp[i - 3], arr[i] + dp[i - 2]);
	}
	cout << dp[n - 1] << endl;

}

int main()
{
	cin >> n;
	for (int i = 0; i < n; i++) {
		cin >> arr[i];
	}
	dp[0] = arr[0];
	dp[1] = arr[0] + arr[1];
	dp[2] = max(arr[0] + arr[2],arr[2]+arr[1]);
	solution();
	return 0;
}