#include <iostream>
#include <map>
#include <string>
using namespace std;

map <string, int> people;
int parent[200002];
int set[200002];

int find(int f) {
	//�θ� �� �ڽ��� ������ ã��
	if (f == parent[f]) {
		return f;
	}
	return parent[f] = find(parent[f]);

}

void Union(int f1, int f2) {
	//�θ� �ٸ��� ���� �θ�(��, ����)���� ����
	int p1 = find(f1);
	int p2 = find(f2);

	if (p1 < p2) {
		parent[p2] = p1;
		set[p1] += set[p2];
	}
	else if(p1 > p2) {
		parent[p1] = p2;
		set[p2] += set[p1];
	}

}

int main() {
	ios_base::sync_with_stdio(false), cin.tie(NULL), cout.tie(NULL);
	int t;
	cin >> t;

	while (t--) {
		string f1, f2;
		int num = 0;
		cin >> num;

		for (int i = 0; i <= 2 * num; i++) {
			parent[i] = i;
			set[i] = 1;
		}

		int cnt = 1;

		while (num--) {
			cin >> f1 >> f2;

			if (people.find(f1) == people.end()) {
				people[f1] = cnt++;
			}

			if (people.find(f2) == people.end()) {
				people[f2] = cnt++;
			}
			Union(people[f1], people[f2]);
			cout << set[find(people[f1])] << '\n'; 

		}

		people.clear();

	}

	return 0;
}