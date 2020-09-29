#include <iostream>
#include <vector>
#include <string>
#include <algorithm>
#define MOD 1000000007
#define INF 1 << 30

using namespace std;
typedef long long ll;

int main(void) {
	int num, i = 0;
	ll ans, a, b = 1, k;
	string s;
	cin >> s >> k;
	while (i < s.size() - 1 && s[i] == s[i + 1])
		i++;
	a = i + 1;
	if (a == s.size()) {
		ans = a * k;
		ans >>= 1;
		cout << ans << "\n";
		return 0;
	}
	ans = a >> 1;
	for (; i < s.size() - 1; i++) {
		if (s[i] == s[i + 1])
			b++;
		else {
			ans += b >> 1;
			b = 1;
		}
	}
	ans += b >> 1;
	ans *= k;
	if (s[0] == s[s.size() - 1]) {
		ans -= ((a >> 1) + (b >> 1)) * (k - 1);
		ans += ((a + b) >> 1) * (k - 1);
	}
	cout << ans << "\n";
	return 0;
}