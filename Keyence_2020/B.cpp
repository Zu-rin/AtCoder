#include <iostream>
#include <vector>
#include <string>
#include <algorithm>
#define rep(i, n) for(i = 0; i < (n); i++)
#define chmax(x, y) x = max(x, y)
#define chmin(x, y) x = min(x, y)
#define MOD 1000000007
#define INF 1 << 30

using namespace std;
typedef long long ll;
typedef pair<int, int> pp;

int main(void) {
	int num, i, x, l, ans = 1;
	cin >> num;
	vector<pp> d(num);
	rep(i, num) {
		cin >> x >> l;
		d[i] = make_pair(x + l, x - l);
	}
	sort(d.begin(), d.end());
	for (x = 0, i = 1; i < num; i++) {
		if (d[i].second >= d[x].first) {
			ans++;
			x = i;
		}
	}
	cout << ans << "\n";
	return 0;
}