#include <iostream>
using namespace std;

long long num[10];
long long stair[10];

void init() {

	for (int i = 1; i < 10; i++) {
		stair[i] = 1;
		//num[i] = 1;
	}

}

int main() {
	
	ios_base::sync_with_stdio(false);
	cin.tie(NULL); cout.tie(NULL);

	int a;
	cin >> a;

	init();

	for (int i = 1; i < a; i++) {

		for (int j = 0; j < 10; j++) {

			if (j == 0) {
				num[j] = stair[j + 1] % 1000000000;
			}
			else if (j == 9) {
				num[j] = stair[j - 1] % 1000000000;
			}
			else {
				num[j] = stair[j - 1] % 1000000000 + stair[j + 1] % 1000000000;
			}

		}

		for (int j = 0; j < 10; j++) {
			stair[j] = num[j];
		}

	}

	int result = 0;
	for (int i = 0; i < 10; i++) {
		result = (result + stair[i]) % 1000000000;
	}
	
	cout << result;

	return 0;
}