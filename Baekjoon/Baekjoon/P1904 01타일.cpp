#include <iostream>
using namespace std;

long long dp[1000002];

void solve(int num) {

	dp[1] = 1; dp[2] = 2;

	for (int i = 3; i <= num; i++) {

		dp[i] = (dp[i - 1] + dp[i - 2]) % 15746;

	}

}

int main() {

	int num;
	cin >> num;

	solve(num);

	cout << dp[num];

	return 0;
}