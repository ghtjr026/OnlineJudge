#include <iostream>
#include <algorithm>
using namespace std;

typedef struct somthing {
	int wight, value;
	bool operator < (somthing a) {
		return wight < a.wight;
	}
}somthing;

int bag[100002];
somthing som[102];

void solve(int n, int k) {

	for (int i = 0; i < n; i++) {

		for (int j = k; j >= 1; j--) {
			if (som[i].wight <= j) {
				bag[j] = max(bag[j], bag[j - som[i].wight] + som[i].value);
			}
		}
	}

}

int main() {

	ios_base::sync_with_stdio(false), cin.tie(NULL), cout.tie(NULL);
	int n, k;
	cin >> n >> k;

	for (int i = 0; i < n; i++) {
		cin >> som[i].wight >> som[i].value;
	}

	sort(som, som + n);
	solve(n, k);
	cout << bag[k];

	return 0;
}