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

int main(void) {
	ll num, i, a, b, dif = 0;
	cin >> num;
	vector<ll> d(num);
	rep(i, num) {
		cin >> a >> b;
		dif += a;
		d[i] = -(2 * a + b);
	}
	sort(d.begin(), d.end());
	rep(i, num + 1) {
		if (dif < 0) {
			cout << i << "\n";
			break;
		}
		dif += d[i];
	}
	return 0;
}