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
	int num, m, q, i;
	cin >> num >> m >> q;
	vector<pp> d(num);
	vector<int> a(m);
	rep(i, num)
		cin >> d[i].second >> d[i].first;
	rep(i, m)
		cin >> a[i];
	sort(d.begin(), d.end(), greater<pp>());
	rep(i, q) {
		int j, l, r, ans = 0;
		cin >> l >> r;
		l--;
		vector<char> ok(m, 1);
		for (j = l; j < r; j++)
			ok[j] = 0;
		for (pp& x : d) {
			int p = -1, s = INF;
			rep(j, m) {
				if (ok[j] and x.second <= a[j] and a[j] < s) {
					p = j;
					s = a[j];
				}
			}
			if (p >= 0) {
				ans += x.first;
				ok[p] = 0;
			}
		}
		cout << ans << "\n";
	}
	return 0;
}