#include <iostream>
using namespace std;

typedef long long ll;

bool arr[1000001];
ll squared[1000001];

int main() {

	ll cnt = 0;
	ll min, max;

	cin >> min >> max;

	for (ll i = 2; i * i < max + 1; i++) {
		squared[i] = i * i;
		cnt++;
	}

	int count = 0;

	for (ll i = 2; i < cnt + 2; i++) {

		if (squared[i] > max) break;

		ll div = min;
		if (div % squared[i] != 0) {
			div = (div / squared[i] + 1) * squared[i];
		}

		for (ll j = div; j < max + 1; j += squared[i]) {
			if (!arr[j - min]) {
				arr[j - min] = true;
				count++;
			}
		}

	}

	cout << max - min - count + 1;

	return 0;
}