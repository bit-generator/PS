#include <iostream>
#include <string>
using namespace std;

string doc, str;
int ans;

int main() {
	ios::sync_with_stdio(false);
	cin.tie(nullptr);

	getline(cin, doc);
	getline(cin, str);

	int pos = doc.find(str, 0);
	while(pos != -1) {
		ans++;
		pos = doc.find(str, pos + str.length());
	}

	cout << ans;
	return 0;
}