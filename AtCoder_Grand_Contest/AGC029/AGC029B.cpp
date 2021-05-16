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
	int num, i, ans = 0;
	ll x;
	multiset<ll> st;
	cin >> num;
	rep(i, num) {
		cin >> x;
		st.insert(x);
	}
	while (st.size()) {
		x = *st.rbegin();
		st.erase(st.find(x));
		ll m = 1, tag;
		while (m < x)
			m <<= 1;
		tag = (~x & (m - 1)) + 1;
		if (st.count(tag)) {
			ans++;
			st.erase(st.find(tag));
		}
	}
	cout << ans << "\n";
	return 0;
}