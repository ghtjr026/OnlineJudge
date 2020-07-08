#include <iostream>
#include <cmath>
using namespace std;

bool squared[4000001];
int decimal[30001];

int main() {

	int num;
	cin >> num;

	for (int i = 2; i <= sqrt(num); i++) {
		if (!squared[i]) {
			for (int j = i * i; j <= num; j += i) {
				squared[j] = true;
			}
		}
	}

	int cnt = 1;
	for (int i = 2; i <= num; i++) {
		if (!squared[i]) {
			decimal[cnt] = decimal[cnt -1] + i;
			cnt++;
		}
	}

	int result = 0, sub = 0, sum = 0;
	for (int i = 1; i < cnt; i++) {
		
		sum = decimal[i] - decimal[sub];

		if (sum == num) {
			result++;
		}
		else if (sum > num) {
			for (; sub < i; sub++) {
				sum = decimal[i] - decimal[sub];
				if (sum == num) {
					result++;
				}
				else if (sum < num) {
					break;
				}
			}
		}

	}

	cout << result;

	return 0;
}