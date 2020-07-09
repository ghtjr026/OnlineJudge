#include <iostream>
#include <algorithm>
using namespace std;

int people[1001];

int main() {

	ios_base::sync_with_stdio(false), cin.tie(0), cout.tie(0);
	int num;
	cin >> num;

	for (int i = 0; i < num; i++) {
		cin >> people[i];
	}

	sort(people, people + num);

	int result = 0;
	for (int i = 0; i < num; i++) {
		result += people[i];
		people[i] = result;
	}

	result = 0;
	for (int i = 0; i < num; i++) {
		result += people[i];
	}
	cout << result;

	return 0;
}