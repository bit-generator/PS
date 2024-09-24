#include <iostream>
#include <list>
#include <string>
using namespace std;

int N;
string com;
char ch;
list<char> ls;

int main() {
	ios::sync_with_stdio(false);
	cin.tie(nullptr);

	while (true) {
		cin >> N;
		if (N == 0) break;

		ls.clear();
		auto it = ls.begin();

		while (N--) {
			cin >> com >> ch;
			if (com == "INSERT") {
				ls.insert(it, ch);
			}
			else if (com == "LEFT") {
				if (it != ls.begin()) it--;
			}
			else {
				if (it != ls.end()) it++;
			}
		}

		for (auto x = ls.begin(); x != ls.end(); x++) {
			cout << *x;
		}
		cout << '\n';
	}

	return 0;
}