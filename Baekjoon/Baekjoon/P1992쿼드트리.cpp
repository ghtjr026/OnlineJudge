#include <iostream>
using namespace std;

char paper[128][128];

void solve(int xStart, int xEnd, int yStart, int yEnd) {

	char confirm = paper[yStart][xStart];
	bool flag = false;
	for (int i = xStart; i < xEnd; i++) {

		for (int j = yStart; j < yEnd; j++) {
			if (confirm != paper[j][i]) {
				flag = true;
				break;
			}
		}
		if (flag) break;

	}

	if (!flag) {
		cout << confirm;
		return;
	}
	else {
		cout << "(";
		//left up side
		solve(xStart, (xStart + xEnd) / 2, yStart, (yStart + yEnd) / 2);
		//right up side
		solve((xStart + xEnd) / 2, xEnd, yStart, (yStart + yEnd) / 2);
		//left down side
		solve(xStart, (xStart + xEnd) / 2, (yStart + yEnd) / 2, yEnd);
		//right down side
		solve((xStart + xEnd) / 2, xEnd, (yStart + yEnd) / 2, yEnd);
		cout << ")";
	}

}

int main() {

	int num;
	cin >> num;

	for (int i = 0; i < num; i++) {

		for (int j = 0; j < num; j++) {
			cin >> paper[i][j];
		}

	}

	solve(0, num, 0, num);

	return 0;
}