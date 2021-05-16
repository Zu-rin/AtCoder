#include <iostream>
#include <vector>
#include <string>

using namespace std;

int VS(int n, vector<string> &s, vector<int> &d) {
	d[n]++;
	if (s[n].size() == d[n])
		return n;
	return VS(s[n][d[n]] - 'a', s, d);
}

int main(void) {
	vector<string> s(3), ans = { "A\n", "B\n", "C\n" };
	vector<int> d(3, -1);
	cin >> s[0] >> s[1] >> s[2];
	cout << ans[VS(0, s, d)];
	return 0;
}