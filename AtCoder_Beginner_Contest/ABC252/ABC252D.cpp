#include <iostream>
#include <vector>
#include <string>
#include <list>
#include <set>
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
	ll num, i, ans, x;
	cin >> num;
	map<ll, ll> mp;
	rep(i, num) {
		cin >> x;
		mp[x]++;
	}
	ans = num * (num - 1) * (num - 2) / 6;
	for (auto it = mp.begin(); it != mp.end(); it++) {
		ll n = (*it).second;
		if (n > 1)
			ans -= n * (n - 1) / 2 * (num - n) + n * (n - 1) * (n - 2) / 6;
	}
	cout << ans << "\n";
	return 0;
}