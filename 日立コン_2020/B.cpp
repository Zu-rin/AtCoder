#include <iostream>
#include <vector>
#include <string>
#include <queue>
#include <algorithm>
#define rep(i, n) for(i = 0; i < (n); i++)
#define chmax(x, y) x = max(x, y)
#define chmin(x, y) x = min(x, y)
#define MOD 1000000007
#define INF 1 << 30

using namespace std;
typedef long long ll;
typedef pair<int, int> pp;

int main(void) {
	int an, bn, cn, i, buf, ans, x, y;
	priority_queue<int, vector<int>, greater<int>> c;
	cin >> an >> bn >> cn;
	vector<int> a(an), b(bn);
	rep(i, an) {
		cin >> a[i];
	}
	rep(i, bn) {
		cin >> b[i];
	}
	rep(i, cn) {
		cin >> x >> y >> buf;
		c.push(a[x - 1] + b[y - 1] - buf);
	}
	sort(a.begin(), a.end());
	sort(b.begin(), b.end());
	ans = min(a[0] + b[0], c.top());
	cout << ans << "\n";
	return 0;
}