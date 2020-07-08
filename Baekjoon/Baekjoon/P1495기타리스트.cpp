#include <iostream>
using namespace std;

int isSelect[101][1001];

void solve(int seq, int m, int vol) {

	for (int i = 0; i <= m; i++) {
		if (isSelect[seq - 1][i]) {
			if (i + vol <= m) {
				isSelect[seq][i + vol] = 1;
			}
			if (i - vol >= 0) {
				isSelect[seq][i - vol] = 1;
			}
		}
	}
	
}

int main() {

	int n, s, m;
	cin >> n >> s >> m;
	isSelect[0][s] = 1;

	for (int i = 1; i <= n; i++) {
		int vol;
		cin >> vol;
		solve(i, m, vol);
	}

	int result = -1;
	for (int i = m; i >= 0; i--) {
		if (isSelect[n][i]) {
			result = i;
			break;
		}
	}

	cout << result;

	return 0;
}