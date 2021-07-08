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
#define INF 1ll << 60

using namespace std;
typedef long long ll;
typedef pair<int, int> pp;

void Eratos(vector<int> &d) {
	int i, j;
	vector<char> p(51, 1);
	p[0] = p[1] = 0;
	for (i = 2; i < p.size(); i++) {
		if (p[i]) {
			d.push_back(i);
			for (j = i << 1; j < p.size(); j += i)
				p[j] = 0;
		}
	}
	return;
}

ll gcd(ll a, ll b) {
	if (b == 0)
		return a;
	return gcd(b, a % b);
}

int main(void) {
	int num, i, j, x;
	ll ans = INF;
	cin >> num;
	vector<int> p, d(num);
	rep(i, num)
		cin >> d[i];
	Eratos(p);
	for (int v = 1; v < (1 << p.size()); v++) {
		int ok = 1;
		ll a = 1;
		rep(i, p.size()) {
			if (v & (1 << i))
				a *= p[i];
		}
		rep(i, num) {
			if (gcd(a, d[i]) == 1) {
				ok = 0;
				break;
			}
		}
		if (ok)
			chmin(ans, a);
	}
	cout << ans << "\n";
	return 0;
}