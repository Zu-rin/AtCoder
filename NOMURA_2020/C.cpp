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

int main(void) {
	int num, i;
	ll k = 1, ans = 0;
	cin >> num;
	num++;
	vector<ll> d(num), f(num);
	rep(i, num)
		cin >> d[i];
	f = d;
	for (i = num - 2; i >= 0; i--)
		f[i] += f[i + 1];
	rep(i, num) {
		if (k < d[i]) {
			ans = -1;
			break;
		}
		ans += min(k, f[i]);
		k -= d[i];
		k <<= 1;
		if (k > INF)
			k = INF;
	}
	cout << ans << "\n";
	return 0;
}