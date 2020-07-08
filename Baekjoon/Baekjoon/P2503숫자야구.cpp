#include <iostream>
using namespace std;

char arr[3025][4];
char arr2[3025][4];
char q[4];
bool a[4];

int cnt;

void init() {

	for (int i = 1; i < 10; i++) {
		for (int j = 1; j < 10; j++) {
			if (j != i) {
				for (int k = 1; k < 10; k++) {
					if (k != i && k != j) {
						arr[cnt][0] = i + '0';
						arr[cnt][1] = j + '0';
						arr[cnt][2] = k + '0';
						cnt++;
					}
				}
			}
		}
	}

}

void solve(int strike, int ball) {
	int temp = 0;

	for (int i = 0; i < cnt; i++) {
		
		int st = 0, ba = 0;
		
		a[0] = false;
		a[1] = false;
		a[2] = false;

		//strike
		if (arr[i][0] == q[0]) {
			st++;
			a[0] = true;
		}
		if (arr[i][1] == q[1]) {
			st++;
			a[1] = true;
		}
		if (arr[i][2] == q[2]) {
			st++;
			a[2] = true;
		}

		//ball
		if (!a[0] && (q[0] == arr[i][1] || q[0] == arr[i][2])) {
			ba++;
		}
		if (!a[1] && (q[1] == arr[i][0] || q[1] == arr[i][2])) {
			ba++;
		}
		if (!a[2] && (q[2] == arr[i][0] || q[2] == arr[i][1])) {
			ba++;
		}

		if (st == strike && ba == ball) {
			arr[temp][0] = arr[i][0];
			arr[temp][1] = arr[i][1];
			arr[temp][2] = arr[i][2];
			temp++;
		}

	}

	cnt = temp;

}

int main() {

	init();

	int num;
	cin >> num;
	int st, ba;
	for (int i = 0; i < num; i++) {
		cin >> q >> st >> ba;
		solve(st, ba);
	}

	cout << cnt;

	return 0;
}