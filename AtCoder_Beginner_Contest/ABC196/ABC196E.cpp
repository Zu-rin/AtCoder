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

class Func {
	ll a = 0, b = INF, c = -INF;

public:
	void input() {
		ll s, t;
		cin >> s >> t;
		if (t == 1) {
			a += s;
			b += s;
			c += s;
		}
		else if (t == 2) {
			chmax(b, s);
			chmax(c, s);
		}
		else {
			chmin(b, s);
			chmin(c, s);
		}
	}

	ll f(ll x) {
		return max(c, min(b, x + a));
	}
};

int main(void) {
	int num, q, i;
	ll x;
	cin >> num;
	Func a;
	rep(i, num)
		a.input();
	cin >> q;
	rep(i, q) {
		cin >> x;
		cout << a.f(x) << "\n";
	}
	return 0;
}