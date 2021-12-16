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
	ll n, i, j, a, b, sl, sr, tl, tr, p, q, r, s;
	cin >> n >> a >> b;
	cin >> p >> q >> r >> s;
	sl = max(1 - a, 1 - b);
	sr = min(n - a, n - b);
	tl = max(1 - a, b - n);
	tr = max(n - a, b - 1);
	vector<string> ans(q - p + 1, string(s - r + 1, '.'));
	rep(i, ans.size()) {
		rep(j, ans[i].size()) {
			ll y = i + p - a, x = j + r - b;
			if (y == x and sl <= y and y <= sr)
				ans[i][j] = '#';
			else if (y == -x and tl <= y and y <= tr)
				ans[i][j] = '#';
		}
		cout << ans[i] << "\n";
	}
	return 0;
}