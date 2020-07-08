#include <iostream>
#include <algorithm>
using namespace std;

int dp[1000002];

void init() {

	dp[0] = 0;
	dp[1] = 0;
	dp[2] = 1;

}

int main() {

	init();
	int num;
	cin >> num;

	for (int i = 3; i < num + 1; i++) {

		if (i % 2 == 0 && i % 3 == 0) {
			dp[i] = min(min(dp[i - 1], dp[i / 2]), dp[i / 3]) + 1;
		}
		else if (i % 2 == 0) {
			dp[i] = min(dp[i - 1], dp[i / 2]) + 1;
		}
		else if (i % 3 == 0) {
			dp[i] = min(dp[i - 1], dp[i / 3]) + 1;
		}
		else {
			dp[i] = dp[i - 1] + 1;
		}

	}

	cout << dp[num];

	return 0;
}