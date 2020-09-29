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

ll Pow(ll n) {
	ll ans = 1, a = n, k = 5;
	while (k > 0) {
		if (k & 1) {
			ans *= a;
		}
		a *= a;
		k >>= 1;
	}
	return ans;
}

void Ini(map<ll, ll> &mp) {
	ll i;
	for (i = -1000; i <= 1000; i++) {
		mp[i] = Pow(i);
	}
	return;
}

int main(void) {
	int num, i;
	ll a, b, x;
	cin >> x;
	for (a = -1000; a <= 1000; a++) {
		for (b = -1000; b <= 1000; b++) {
			if (Pow(a) - Pow(b) == x) {
				cout << a << " " << b << "\n";
				return 0;
			}
		}
	}
	return 0;
}