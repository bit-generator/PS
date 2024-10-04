#include <iostream>
#include <string>
using namespace std;

int T, N;
string str[20000];
string sorted[20000];

bool stringCmp(const string& a, const string& b) {
	if (a.length() == b.length()) return a < b;
	return a.length() < b.length();
}

void merge(int start, int mid, int last) {
	int idx1 = start, idx2 = mid;
	int pos = start;

	while (idx1 < mid && idx2 < last) {
		if (stringCmp(str[idx1], str[idx2])) {
			sorted[pos++] = str[idx1++];
		}
		else {
			sorted[pos++] = str[idx2++];
		}
	}

	while (idx1 < mid) sorted[pos++] = str[idx1++];
	while (idx2 < last) sorted[pos++] = str[idx2++];

	for (int i = start; i < last; i++) {
		str[i] = sorted[i];
	}
}

void mergeSort(int start, int last) {
	if (last - start <= 1) return;

	int mid = (start + last) / 2;
	mergeSort(start, mid);
	mergeSort(mid, last);
	merge(start, mid, last);
}

int main() {
	ios::sync_with_stdio(false);
	cin.tie(nullptr);

	cin >> T;
	for (int tc = 1; tc <= T; tc++) {
		cin >> N;
		for (int i = 0; i < N; i++) cin >> str[i];

		mergeSort(0, N);
		cout << '#' << tc << '\n';

		string tmp = "";
		for (int i = 0; i < N; i++) {
			if (sorted[i] == tmp) continue;
			cout << sorted[i] << '\n';
			tmp = sorted[i];
		}
	}

	return 0;
}