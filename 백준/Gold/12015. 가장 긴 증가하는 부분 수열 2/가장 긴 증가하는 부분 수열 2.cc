#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

int N, A;
vector<int> seq;

int main() {
	ios::sync_with_stdio(false);
	cin.tie(nullptr);

	cin >> N;

	for (int i = 0; i < N; i++) {
		cin >> A;
        auto it = lower_bound(seq.begin(), seq.end(), A);
		if (it == seq.end()) {
			seq.push_back(A);
		}
        else {
            *it = A;
        }
	}

	cout << seq.size();
	return 0;
}