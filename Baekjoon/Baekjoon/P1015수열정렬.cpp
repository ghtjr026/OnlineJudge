#include <fstream>
#include <iostream>
#pragma warning (disable : 4996)
using namespace std;

typedef struct A {
	int w, c;
};

A arr[1001];
int P[1001];

void swap(int* a, int* b) {
	int temp = *a;
	*a = *b;
	*b = temp;
}

bool comp(A a, A b) {
	if (a.w == b.w) return a.c <= b.c;
	return a.w < b.w;
}

void Qsort(int start, int end) {
	int pivot = start;
	int j = pivot;
	int i = start + 1;

	if (start < end) {
		for (; i < end; i++) {
			if (comp(arr[i], arr[pivot])) {
				j++;
				swap(&arr[i].w, &arr[j].w);
				swap(&arr[i].c, &arr[j].c);
			}
		}
		swap(&arr[start].w, &arr[j].w);
		swap(&arr[start].c, &arr[j].c);
		pivot = j;

		Qsort(start, pivot);
		Qsort(pivot + 1, end);
	}
}

int main() {


	int num;
	cin >> num;
	for (int i = 0; i < num; i++) {
		cin >> arr[i].w;
		arr[i].c = i;
	}

	Qsort(0, num);

	for (int i = 0; i < num; i++) {
		P[arr[i].c] = i;
	}

	for (int i = 0; i < num; i++) {
		cout << P[i] << ' ';
	}

	return 0;
}