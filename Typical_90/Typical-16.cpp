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
	ll num, i, j, a, b, c, ans = INF;
	cin >> num >> a >> b >> c;
	rep(i, 10000) {
		rep(j, 10000 - i) {
			ll k = num - a * i - b * j;
			if (k < 0)
				break;
			if (k % c == 0)
				chmin(ans, k / c + i + j);
		}
	}
	cout << ans << "\n";
	return 0;
}