#include <iostream>
#define BLUE 1
#define WHITE 0
using namespace std;

int paper[128][128];
int white, blue;

void solve(int xStart, int xEnd, int yStart, int yEnd) {

	int confirm = paper[xStart][yStart];
	bool flag = false;
	for (int i = xStart; i < xEnd; i++) {
		
		for (int j = yStart; j < yEnd; j++) {
			if (confirm != paper[i][j]) {
				flag = true;
			}
		}

	}

	if (!flag) {
		confirm == BLUE ? blue++ : white++;
	}
	else {
		//left up side
		solve(xStart, (xStart + xEnd) / 2, yStart, (yStart + yEnd) / 2);
		//right up side
		solve((xStart + xEnd) / 2, xEnd, yStart, (yStart + yEnd) / 2);
		//right down side
		solve((xStart + xEnd) / 2, xEnd, (yStart + yEnd) / 2, yEnd);
		//left down side
		solve(xStart, (xStart + xEnd) / 2, (yStart + yEnd) / 2, yEnd);

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
	cout << white << endl << blue;

	return 0;
}