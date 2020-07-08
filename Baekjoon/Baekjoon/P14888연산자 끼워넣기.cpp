#include <iostream>
#include <algorithm>
#define INF 987654321
#define reINF -987654321
using namespace std;

int Operator[4];
int A[11];
int Max = reINF, Min = INF;

void solve(int num, int sum, int seq) {

	int choice = -1;
	for (int i = 0; i < 4; i++) {
		if (Operator[i]) {
			Operator[i]--;
			choice = i;
			switch (choice)
			{
			case 0:
				sum += A[seq];
				solve(num, sum, seq + 1);
				sum -= A[seq];
				break;
			case 1:
				sum -= A[seq];
				solve(num, sum, seq + 1);
				sum += A[seq];
				break;
			case 2:
				sum *= A[seq];
				solve(num, sum, seq + 1);
				sum /= A[seq];
				break;
			case 3:
				int Remainder = sum % A[seq];
				sum /= A[seq];
				solve(num, sum, seq + 1);
				sum *= A[seq];
				sum += Remainder;
				break;
			}
			Operator[choice]++;
		}
	}

	if (choice == -1) {
		Max = max(Max, sum);
		Min = min(Min, sum);
	}

}

int main() {

	int num;
	cin >> num;

	for (int i = 0; i < num; i++) {
		cin >> A[i];
	}

	for (int i = 0; i < 4; i++) {
		cin >> Operator[i];
	}

	solve(num, A[0], 1);

	cout << Max << '\n' << Min;

	return 0;
}