#include<iostream>
using namespace std;
//2*n Ÿ�ϸ�
//like fibonacci
int n;
int arr[1001];
void solution()
{
	arr[0] = 1;
	arr[1] = 1;
	if (n == 1) cout << arr[0];
	else {
		for (int i = 2; i <= n; i++) {
			arr[i] = (arr[i - 1] % 10007) + (arr[i - 2] % 10007);
		}
		
		cout << arr[n]%10007;
	}//�Ǻ���ġ ������ ����
}
int main() {
	cin >> n;
	solution();
	return 0;
}