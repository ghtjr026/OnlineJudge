#include <iostream>
using namespace std;

void solve(int n, int L) {

	for (int i = L; i < 101; i++) {

		int Lx = n - i * (i + 1) / 2;

		if (Lx % i == 0) {

			int temp = Lx / i + 1;

			if (temp >= 0) {

				for (int j = 0; j < i; j++) {

					cout << j + temp << ' ';

				}
				cout << '\n';
				return;
			}

		}

	}

	cout << "-1\n";
	return;

}

int main() {

	int n, L;
	cin >> n >> L;

	solve(n, L);

	return 0;
}