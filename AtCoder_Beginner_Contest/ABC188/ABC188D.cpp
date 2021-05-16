#include <iostream>
#include <vector>
#include <string>
#include <list>
#include <map>
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
	int num, i;
	ll k, a, b, c, ans = 0, s = 0, x = 0;
	map<ll, ll> mp;
	cin >> num >> k;
	rep(i, num) {
		cin >> a >> b >> c;
		mp[a] += c;
		mp[b + 1] -= c;
	}
	for (auto it = mp.begin(); it != mp.end(); it++) {
		ans += ((*it).first - x) * min(s, k);
		s += (*it).second;
		x = (*it).first;
	}
	cout << ans << "\n";
	return 0;
}