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
typedef pair<ll, ll> pp;

int main(void) {
	int i, q, t;
	ll x, c;
	deque<pp> que;
	cin >> q;
	rep(i, q) {
		cin >> t >> c;
		if (t == 1) {
			x = c;
			cin >> c;
			que.push_back(pp(c, x));
		}
		else {
			ll ans = 0;
			while (c) {
				pp a = que.front();
				que.pop_front();
				if (c < a.first) {
					ans += c * a.second;
					a.first -= c;
					que.push_front(a);
					c = 0;
				}
				else {
					ans += a.first * a.second;
					c -= a.first;
				}
			}
			cout << ans << "\n";
		}
	}
	return 0;
}