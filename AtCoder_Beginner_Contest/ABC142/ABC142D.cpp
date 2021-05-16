#include <iostream>
#include <vector>
#include <string>
#include <cmath>
#include <algorithm>
#define MOD 1000000007
#define INF 1 << 30

using namespace std;
typedef long long ll;

ll gcd(ll a, ll b) {
	if (b == 0)
		return a;
	return gcd(b, a % b);
}

int main(void) {
	int num, i, j, ans = 1;
	ll a, b, g, k;
	cin >> a >> b;
	g = gcd(a, b);
	k = (ll)sqrt(g) + 1;
	vector<int> d(k, true);
	for (i = 2; i < k; i++) {
		if (d[i]) {
			for (j = i << 1; j < k; j += i)
				d[j] = false;
			if (g % i == 0) {
				ans++;
				while (g % i == 0)
					g /= i;
			}
		}
	}
	if (g != 1)
		ans++;
	cout << ans << "\n";
	return 0;
}