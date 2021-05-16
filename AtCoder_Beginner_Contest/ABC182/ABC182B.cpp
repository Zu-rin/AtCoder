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
	ll num, i, j, ans, n = 0;
	cin >> num;
	vector<ll> d(num);
	rep(i, num)
		cin >> d[i];
	ans = d[0];
	for (i = 2; i <= 1000; i++) {
		ll k = 0;
		rep(j, num) {
			if (d[j] % i == 0)
				k++;
		}
		if (n < k) {
			n = k;
			ans = i;
		}
	}
	cout << ans << "\n";
	return 0;
}