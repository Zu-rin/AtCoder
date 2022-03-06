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
	int num, i, k, q;
	ll x;
	map<ll, int> mp;
	cin >> num;
	rep(i, num) {
		cin >> q >> x;
		if (q == 1) {
			mp[x]++;
		}
		else if (q == 2) {
			cin >> k;
			reverse_iterator<decltype(mp)::iterator> it(mp.upper_bound(x));
			while (it != mp.rend()) {
				k -= it->second;
				if (k <= 0) {
					cout << it->first << "\n";
					break;
				}
				it++;
			}
			if (k > 0)
				printf("-1\n");
		}
		else {
			cin >> k;
			auto it = mp.lower_bound(x);
			while (it != mp.end()) {
				k -= it->second;
				if (k <= 0) {
					cout << it->first << "\n";
					break;
				}
				it++;
			}
			if (k > 0)
				printf("-1\n");
		}
	}
	return 0;
}