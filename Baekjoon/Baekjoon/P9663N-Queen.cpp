#include <iostream>
#include <cmath>
using namespace std;

int board[16][16];
int dx[4] = { -1, 1, 1 ,-1 };
int dy[4] = { -1, -1, 1 ,1 };
int cnt;

bool isRange(int num, int row, int cal) {

	if (0 <= row && row < num) {
		if (0 <= cal && cal < num) {
			return true;
		}
	}
	return false;
}

void Select(int num, int row, int cal) {

	//啊肺 贸府
	for (int i = 0; i < num; i++) {
		board[row][i]++;
	}

	//技肺贸府
	for (int i = 0; i < num; i++) {
		board[i][cal]++;
	}

	//措阿急 贸府
	for (int i = 0; i < 4; i++) {

		int cnt = 1;
		while (1) {
			if (isRange(num, row + (dx[i] * cnt), cal + (dy[i] * cnt))) {
				board[row + (dx[i] * cnt)][cal + (dy[i] * cnt)]++;
				cnt++;
			}
			else {
				break;
			}
		}

	}

}

void nonSelect(int num, int row, int cal) {

	//啊肺 贸府
	for (int i = 0; i < num; i++) {
		board[row][i]--;
	}

	//技肺贸府
	for (int i = 0; i < num; i++) {
		board[i][cal]--;
	}

	//措阿急 贸府
	for (int i = 0; i < 4; i++) {

		int cnt = 1;
		while (1) {
			if (isRange(num, row + (dx[i] * cnt), cal + (dy[i] * cnt))) {
				board[row + dx[i] * cnt][cal + dy[i] * cnt]--;
				cnt++;
			}
			else {
				break;
			}
		}

	}

}

void solve(int num, int row, int cal, int s) {

	int x = -1, y = -1;
	for (int i = row; i < num; i++) {

		for (int j = 0; j < num; j++) {
			if (board[i][j] == 0) {
				x = i, y = j;
				Select(num, x, y);
				solve(num, row + 1, 0, s + 1);

				nonSelect(num, x, y);
			}
		}
		if (x != -1) break;
	}

	if (x == -1 && s == num) {
		cnt++;
	}
	return;

}

int main() {

	int num;
	cin >> num;

	solve(num, 0, 0, 0);

	cout << cnt;

	return 0;
}