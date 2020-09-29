#include <iostream>
#include <vector>
#include <string>
#include <algorithm>

using namespace std;
typedef long long ll;

int main(void) {
	int i;
	ll n, a = 0, ans = 0, l, r;
	string s;
	cin >> n >> s;
	if (s.find("B") >= s.size()) {
		n *= s.size();
		cout << ((n * (n + 1)) >> 1) << "\n";
		return 0;
	}
	l = s.find("B");
	for (i = l; i < s.size(); i++) {
		if (s[i] == 'B') {
			ans += (a * (a + 1)) >> 1;
			a = 0;
		}
		else
			a++;
	}
	ans *= n;
	ans += (a * (a + 1)) >> 1;
	ans += (l * (l + 1)) >> 1;
	a += l;
	ans += (n - 1) * (a * (a + 1) >> 1);
	cout << ans << "\n";
	return 0;
}