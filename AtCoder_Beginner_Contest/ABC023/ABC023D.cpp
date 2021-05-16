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

int num;

int Judge(ll x, vector<ll> &a, vector<ll> &b) {
	int i, sum = 0;
	vector<int> d(num + 1, 0);
	rep(i, num) {
		if (x - a[i] < 0)
			return 0;
		ll k = (x - a[i]) / b[i];
		d[min(k, (ll)num)]++;
	}
	rep(i, num) {
		sum += d[i];
		if (sum > i + 1)
			return 0;
	}
	return 1;
}

int main(void) {
	int i;
	ll l = 0, r = INF;
	cin >> num;
	vector<ll> a(num), b(num);
	rep(i, num)
		cin >> a[i] >> b[i];
	while (l + 1 < r) {
		ll p = (l + r) / 2;
		if (Judge(p, a, b))
			r = p;
		else
			l = p;
	}
	cout << r << "\n";
	return 0;
}