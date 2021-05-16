#include <iostream>
#include <vector>
#include <string>
#include <algorithm>
#define MOD 1000000007
#define INF 1 << 30

using namespace std;
typedef long long ll;

ll Pow(ll n, ll k) {
	ll ans = 1;
	for (int i = 0; i < k; i++) {
		ans *= n;
	}
	return ans;
}

int main(void) {
	ll i, a, b, x, ans = 0;
	cin >> a >> b >> x;
	for (i = 1; i < 11; i++) {
		ans = max(ans, min((x - b * i) / a, Pow(10, i) - 1ll));
	}
	cout << min(ans, Pow(10, 9)) << "\n";
	return 0;
}