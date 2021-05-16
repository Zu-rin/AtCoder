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

int Judge(ll x, ll y) {
	return !((x + y - 1) & 1);
}

int main(void) {
	int ans = 0;
	ll n, i;
	cin >> n;
	n <<= 1;
	for (i = 1; i * i <= n; i++) {
		if (n % i == 0) {
			if (Judge(i, n / i))
				ans++;
			if (Judge(n / i, i))
				ans++;
		}
	}
	cout << ans << "\n";
	return 0;
}