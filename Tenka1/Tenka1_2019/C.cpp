#include <iostream>
#include <string>
#include <vector>
#include <algorithm>
using namespace std;

int main(void) {
	int num, i = 0, buf = 0, ans = 200000;
	string s;
	cin >> num >> s;
	vector<int> b(num + 1, 0), w(num + 1, 0);
	while (i < num) {
		if (s[i] == '#')
			buf++;
		b[++i] = buf;
	}
	buf = 0;
	while (i > 0) {
		if (s[i] == '.')
			buf++;
		w[--i] = buf;
	}
	for (i = 0; i <= num; i++)
		ans = min(ans, b[i] + w[i]);
	cout << ans << "\n";
	return 0;
}