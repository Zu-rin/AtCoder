#include <iostream>
#include <vector>
#include <string>
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

int main(void) {
	int x, y, na, nb, nc, num, i;
	ll buf, ans = 0;
	cin >> x >> y >> na >> nb >> nc;
	vector<ll> a(na), b(nb);
	priority_queue<ll> c;
	rep(i, na)
		cin >> a[i];
	rep(i, nb)
		cin >> b[i];
	rep(i, nc) {
		cin >> buf;
		c.push(buf);
	}
	sort(a.begin(), a.end(), greater<ll>());
	sort(b.begin(), b.end(), greater<ll>());
	rep(i, x)
		ans += a[i];
	rep(i, y)
		ans += b[i];
	while (x > 0 && y > 0 && !c.empty()) {
		if (a[x - 1] <= b[y - 1]) {
			if (a[x - 1] < c.top()) {
				ans += c.top() - a[x - 1];
				x--;
			}
			else break;
		}
		else {
			if (b[y - 1] < c.top()) {
				ans += c.top() - b[y - 1];
				y--;
			}
			else break;
		}
		c.pop();
	}
	while (x > 0 && !c.empty()) {
		if (a[x - 1] < c.top()) {
			ans += c.top() - a[x - 1];
			x--;
			c.pop();
		}
		else break;
	}
	while (y > 0 && !c.empty()) {
		if (b[y - 1] < c.top()) {
			ans += c.top() - b[y - 1];
			y--;
			c.pop();
		}
		else break;
	}
	cout << ans << "\n";
	return 0;
}