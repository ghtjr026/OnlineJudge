#include <iostream>
#include <algorithm>
#include <vector>
using namespace std;

vector<vector<int>> triangle;

int main() {

	ios_base::sync_with_stdio(false);
	cin.tie(NULL); cout.tie(NULL);
	
	int num;
	cin >> num;

	triangle.resize(num);

	for (int i = 1; i < num + 1; i++) {

		for (int j = 0; j < i; j++) {
			int a;
			cin >> a;
			triangle[i - 1].push_back(a);
		}

		triangle[i - 1].push_back(0);
	}

	for (int i = 1; i < num; i++) {

		for (int j = 0; j <= i + 1; j++) {

			if (j == 0) {
				triangle[i][j] += triangle[i - 1][j];
			}
			else {
				triangle[i][j] += max(triangle[i - 1][j], triangle[i - 1][j - 1]);
			}

		}

	}

	int result = 0;
	for (int i = 0; i < num; i++) {
		result = max(triangle[num - 1][i], result);
	}

	cout << result;

	return 0;
}