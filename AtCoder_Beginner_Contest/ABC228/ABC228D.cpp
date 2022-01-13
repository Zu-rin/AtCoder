#include <iostream>
#include <vector>
#include <string>
#include <list>
#include <set>
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
	int num, i, q, t;
	ll n = 1ll << 20, mask = (1ll << 20) - 1, x;
	vector<int> buf(n);
	vector<ll> d(n, -1);
	rep(i, n)
		buf[i] = i;
	set<int> st(buf.begin(), buf.end());
	cin >> q;
	rep(i, q) {
		cin >> t >> x;
		if (t == 1) {
			auto it = st.lower_bound(x & mask);
			if (it == st.end())
				it = st.begin();
			d[*it] = x;
			st.erase(it);
		}
		else {
			cout << d[x & mask] << "\n";
		}
	}
	return 0;
}