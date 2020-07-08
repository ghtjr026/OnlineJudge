#include <iostream>
#include <algorithm>
using namespace std;

int wine[10001];
int drink[10001];

void init() {

	drink[1] = wine[1];
	drink[2] = wine[1] + wine[2];

}

void solve(int num) {

	init();
	for (int i = 3; i < num + 1; i++) {
		drink[i] = max(max(drink[i - 1], drink[i - 2] + wine[i]), drink[i - 3] + wine[i - 1] + wine[i]);
	}

}

int main() {

	int num;
	cin >> num;

	for (int i = 1; i < num + 1; i++) {
		cin >> wine[i];
	}

	solve(num);

	cout << drink[num];

	return 0;
}