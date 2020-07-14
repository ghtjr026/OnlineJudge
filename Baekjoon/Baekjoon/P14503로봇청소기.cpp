#include <iostream>
using namespace std;

int area[50][50];
int dx[4] = { -1,0,1,0 };
int dy[4] = { 0,1,0,-1 };
int dir, cnt;


void solve(int n, int m, int x, int y) {

	if (area[x][y] == 0) {
		cnt++;
		area[x][y] = 2;
	}

	bool flag = false;

	for (int i = 0; i < 4; i++) {
		dir = (dir - 1 + 4) % 4;
		if (area[x + dx[dir]][y + dy[dir]] == 0) {
			flag = true;
			break;
		}
	}

	if (flag) {
		solve(n, m, x + dx[dir], y + dy[dir]);
	}
	else {

		int subDir = (dir - 2 + 4) % 4;
		if (area[x + dx[subDir]][y + dy[subDir]] != 1) {
			solve(n, m, x + dx[subDir], y + dy[subDir]);
		}
		else {
			return;
		}

	}
	return;

}

int main() {

	int n, m;
	cin >> n >> m;

	int x, y;

	cin >> x >> y >> dir;

	for (int i = 0; i < n; i++) {

		for (int j = 0; j < m; j++) {
			cin >> area[i][j];
		}

	}

	solve(n, m, x, y);

	cout << cnt;

	return 0;
}