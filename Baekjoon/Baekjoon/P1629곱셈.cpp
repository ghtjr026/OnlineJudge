#include <iostream>
using namespace std;

long long int A, B, C;

long long int solve(long long int result, long long int num) {
	
	if (num == 0) {
		return 1;
	}
	else if (num == 1) {
		return result;
	}

	//È¦¼ö
	if (num % 2 > 0) {
		return solve(result, num - 1) * result % C;
	}
	long long int half = solve(result, num / 2);
	half %= C;
	return half * half % C;
		
}

int main() {

	cin >> A >> B >> C;

	cout << solve(A, B) % C;

	return 0;
}