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
	int num, i;
	ll k, x, a, ans = 0;
	priority_queue<ll> que;
	cin >> num >> k >> x;
	rep(i, num) {
		cin >> a;
		ll b = min(k, a / x);
		k -= b;
		a -= b * x;
		if (a) {
			que.push(a);
			ans += a;
		}
	}
	while (k and !que.empty()) {
		ans -= que.top();
		que.pop();
		k--;
	}
	cout << ans << "\n";
	return 0;
}