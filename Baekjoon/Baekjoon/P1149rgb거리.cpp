#include <iostream>
#define INF 987654321
using namespace std;

int rgb[1002][3];

void stroe(int num, int color, int wight) {

	for (int i = 0; i < 3; i++) {

		if (i != color) {
			rgb[num][color] = wight + rgb[num - 1][i] < rgb[num][color] ? wight + rgb[num - 1][i] : rgb[num][color];
		}

	}

}

void solve(int num) {

	for (int i = 1; i < num + 1; i++) {

		int r, g, b;
		cin >> r >> g >> b;

		stroe(i, 0, r);
		stroe(i, 1, g);
		stroe(i, 2, b);

	}

}

void init() {

	rgb[0][0] = 0;
	rgb[0][1] = 0;
	rgb[0][2] = 0;

	for (int i = 1; i < 1002; i++) {
		rgb[i][0] = INF;
		rgb[i][1] = INF;
		rgb[i][2] = INF;
	}

}

void print(int num) {

	int min = INF;
	for (int i = 0; i < 3; i++) {
		min = rgb[num][i] < min ? rgb[num][i] : min;
	}

	cout << min;
}

int main() {

	init();

	int num;
	cin >> num;

	solve(num);
	print(num);

	return 0;
}