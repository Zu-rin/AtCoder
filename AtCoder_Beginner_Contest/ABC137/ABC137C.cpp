#include <iostream>
#include <string>
#include <vector>
#include <algorithm>

using namespace std;
typedef long long ll;

int main(void) {
	int num, i, j, k;
	ll ans = 0, a;
	cin >> num;
	vector<string> s(num);
	for (i = 0; i < num; i++) {
		cin >> s[i];
		sort(s[i].begin(), s[i].end());
	}
	sort(s.begin(), s.end());
	for (a = 1, i = 0; i < num - 1; i++) {
		if (s[i] == s[i + 1])
			a++;
		else {
			ans += (a * (a - 1)) >> 1;
			a = 1;
		}
	}
	ans += (a * (a - 1)) >> 1;
	cout << ans << "\n";
	return 0;
}