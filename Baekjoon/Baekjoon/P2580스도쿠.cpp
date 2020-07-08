#include <iostream>
#include <algorithm>
using namespace std;

int t;
int n_sudoku[9][9];
char s_sudoku[9][9];
bool n_s_sudoku[9][10];

bool isposible(int x, int y, int num) {

	//가로줄
	for (int i = 0; i < 9; i++) {
		if (n_sudoku[x][i] == num) return false;
	}

	//세로줄
	for (int i = 0; i < 9; i++) {
		if (n_sudoku[i][y] == num) return false;
	}

	return true;
}

void print() {

	for (int i = 0; i < 9; i++) {
		for (int j = 0; j < 9; j++) {
			cout << n_sudoku[i][j] << " ";
		}
		cout << '\n';
	}
	cout << '\n';

}

int play(int row) {

	int x = -1;
	int y = -1;
	for (int i = row; i < 9; i++) {
		for (int j = 0; j < 9; j++) {
			if (n_sudoku[i][j] == 0) {
				x = i;
				y = j;
				break;
			}
		}
		if (x != -1) break;
	}

	if (x == -1) {
		print();
		return 1;
	}

	for (int num = 1; num < 10; num++) {
		if (isposible(x, y, num) && !n_s_sudoku[s_sudoku[x][y] - 'a'][num]) {
			n_sudoku[x][y] = num;
			n_s_sudoku[s_sudoku[x][y] - 'a'][num] = true;
			if (play(x)) return 1;
			n_sudoku[x][y] = 0;
			n_s_sudoku[s_sudoku[x][y] - 'a'][num] = false;
		}
	}
	return 0;
}

int main() {

	for (int i = 0; i < 9; i++) {
		for (int j = 0; j < 9; j++) {
			cin >> n_sudoku[i][j];
		}
	}

	char alpabet = 'a';
	for (int i = 0; i < 9; i++) {
		if (i != 0 && i % 3 == 0) {
			alpabet += 3;
		}
		int cnt = 0;
		for (int j = 0; j < 9; j++) {
			if (j != 0 && j % 3 == 0) {
				cnt++;
			}
			s_sudoku[i][j] = alpabet + cnt;
		}
	}

	for (int i = 0; i < 9; i++) {
		for (int j = 0; j < 9; j++) {
			n_s_sudoku[s_sudoku[i][j] - 'a'][n_sudoku[i][j]] = true;
		}
	}

	play(0);

	for (int i = 0; i < 9; i++) {
		for (int j = 0; j < 10; j++) {
			n_s_sudoku[i][j] = false;
		}
	}




	return 0;
}