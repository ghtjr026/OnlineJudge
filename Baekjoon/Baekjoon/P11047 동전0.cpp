#include <iostream>
using namespace std;

int coin[10];
int num, money;

int solve() {

	int cnt = 0;
	for (int i = num - 1; i >= 0; i--) {
		if (coin[i] <= money) {
			cnt += money / coin[i];
			money %= coin[i];
		}
	}

	return cnt;
}

int main() {

	cin >> num >> money;

	for (int i = 0; i < num; i++) {
		cin >> coin[i];
	}

	cout << solve();

	return 0;
}