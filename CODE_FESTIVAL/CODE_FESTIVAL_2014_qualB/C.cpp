#include <iostream>
#include <vector>
#include <string>
#include <list>
#include <queue>
#include <map>
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

int And(const vector<int>& a, const vector<int>& b) {
	int i, ans = 0;
	rep(i, a.size())
		ans += min(a[i], b[i]);
	return ans;
}

int main(void) {
	int n, i, ok = true;
	string s, t, x;
	cin >> s >> t >> x;
	n = s.size() >> 1;
	vector<int> a(26, 0), b(26, 0), c(26, 0);
	rep(i, s.size()) {
		a[s[i] - 'A']++;
		b[t[i] - 'A']++;
		c[x[i] - 'A']++;
	}
	rep(i, c.size()) {
		if (c[i] > a[i] + b[i]) {
			ok = false;
			break;
		}
	}
	if (And(a, c) < n || And(b, c) < n)
		ok = false;
	if (ok)
		printf("YES\n");
	else
		printf("NO\n");
	return 0;
}