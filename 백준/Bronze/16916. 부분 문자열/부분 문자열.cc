#include <iostream>
#include <string>
#include <vector>
using namespace std;

string str1, str2;
int ans;

int main() {
	ios::sync_with_stdio(false);
	cin.tie(nullptr);

	cin >> str1 >> str2;

	vector<int> f(str2.length());
	int j = 0;
	for (int i = 1; i < str2.length(); i++) {
		while (j > 0 && str2[i] != str2[j]) j = f[j - 1];
		if (str2[i] == str2[j]) f[i] = ++j;
	}

	int len = str1.length();
	j = 0;

	for (int i = 0; i < len; i++) {
		while (j > 0 && str1[i] != str2[j]) j = f[j - 1];
		if (str1[i] == str2[j]) ++j;

		if (j == str2.length()) {
			ans = 1;
			break;
		}
	}

	cout << ans;
	return 0;
}