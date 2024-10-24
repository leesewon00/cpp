#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

int n;
int dp[10000001]; // 추후 크기 수정
int mod = 1000000007;

int main() {
	ios_base::sync_with_stdio(false);
	cin.tie(nullptr);
	cout.tie(nullptr);

	dp[1] = 1;
	dp[2] = 2;
	dp[3] = 4;
	dp[4] = 7;

	for (int i = 5; i <= 10000000; i++) {
		dp[i] = ((dp[i - 1] + dp[i - 2]) % mod + dp[i - 3]) % mod;
	}

	int t; cin >> t;

	while (t--) {
		cin >> n;

		cout << dp[n] << '\n';
	}

}
