#include <iostream>
#include <algorithm>
using namespace std;

typedef struct room {
	int start, fin;
	bool operator < (room a) {
		if (fin == a.fin) {
			return start < a.start;
		}
		return fin < a.fin;
	}
}room;

room conference[100001];

void solve(int num) {

	int fin = 0;
	int result = 0;
	for (int i = 0; i < num; i++) {
		
		if (fin <= conference[i].start) {
			fin = conference[i].fin;
			result++;
		}

	}
	cout << result;

}

int main() {

	int num;
	cin >> num;

	for (int i = 0; i < num; i++) {
		cin >> conference[i].start >> conference[i].fin;
	}

	sort(conference, conference + num);

	solve(num);

	return 0;
}