#include <iostream>
#include <vector>
#include <string>
#include <algorithm>
#define MOD 1000000007
#define INF 1 << 30

using namespace std;
typedef long long ll;

int main(void) {
	int num, i, a = 0, b = 0, ans = 0;
	string s, r;
	cin >> s;
	r = s;
	reverse(r.begin(), r.end());
	for (i = 0; i < s.size() / 2; i++) {
		if (s[i] == r[i])
			a++;
		else
			b++;
	}
	if (b == 1)
		ans = a * 50 + 48;
	else
		ans = (a + b) * 50;
	if ((s.size() & 1) && b > 0) {
		ans += 25;
	}
	cout << ans << "\n";
	return 0;
}