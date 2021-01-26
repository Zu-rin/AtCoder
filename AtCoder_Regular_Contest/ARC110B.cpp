#include <iostream>
#include <vector>
#include <string>
#include <list>
#include <queue>
#include <algorithm>
#define rep(i, n) for(i = 0; i < (n); i++)
#define chmax(x, y) x = max(x, y)
#define chmin(x, y) x = min(x, y)
#define MOD 1000000007
#define PI 3.14159265358979323846
#define INF 1 << 30

using namespace std;
typedef long long ll;
typedef pair<int, int> pp;

int Judge(string & s) {
	int i = (int)s.find("0"), b = 0, ans = 1;
	if (i < 0) {
		if (s.size() >= 3)
			return 0;
		return 1;
	}
	if (i - b > 3)
		return 0;
	for (b = ++i; i < s.size(); i++) {
		if (s[i] == '0') {
			if (i - b != 2)
				return 0;
			b = i + 1;
			ans++;
		}
	}
	if (s.size() - b == 0)
		return ans;
	if (s.size() - b <= 2)
		return ans + 1;
	else
		return 0;
}

int main(void) {
	ll num, i, l;
	ll ans = 0;
	string s;
	cin >> num >> s;
	if (l = Judge(s)) {
		if (l == 1) {
			if (s == "1")
				printf("20000000000");
			else
				printf("10000000000");
		}
		else
			cout << (ll)1e10 - l + 1 << "\n";
	}
	else
		printf("0\n");

	return 0;
}