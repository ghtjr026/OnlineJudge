#include <iostream>
#include <algorithm>
using namespace std;

int result[100001];

int main() {

	int num;
	cin >> num;

	int  sum = 0, Max = -1001;

	for (int i = 0; i < num; i++) {

		int a;
		cin >> a;

		sum += a;
		result[i] = max(a, sum);

		if (result[i] == a) {
			sum = a;
		}

		Max = max(sum, Max);
	}

	cout << Max;
	
	return 0;
}