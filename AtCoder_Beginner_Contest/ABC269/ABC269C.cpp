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
	ll num, i, k = 1;
	vector<ll> d;
	cin >> num;
	while (k <= num) {
		if (k & num) {
			d.push_back(k);
		}
		k <<= 1;
	}
	rep(k, 1 << d.size()) {
		ll a = 0;
		for (i = 0; (1ll << i) <= k; i++) {
			if ((1ll << i) & k)
				a += d[i];
		}
		cout << a << "\n";
	}
	return 0;
}