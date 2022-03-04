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
typedef pair<int, int> pp;

ll MSB(ll n) {
	// most significant bit
	// ®” n ‚ÌÅãˆÊbit‚Ì‚İ—§‚Á‚½®”‚ğ•Ô‚·D
	if (n < 0)
		return -1;
	int l = 0, r = 63;
	while (r - l > 1) {
		int k = (l + r) / 2;
		if ((1ll << k) <= n)
			l = k;
		else
			r = k;
	}
	return 1ll << l;
}

int main(void) {
	int num, i;
	ll x, y, k;
	cin >> num;
	rep(i, num) {
		cin >> x >> y;
		y -= x << 1;
		k = MSB(y);
		while (y > 0 and k > 0) {
			if (!(k & x) and k <= y)
				y -= k;
			k >>= 1;
		}
		if (!y)
			printf("Yes\n");
		else
			printf("No\n");
	}
	return 0;
}