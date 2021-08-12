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

// nˆÈ‰º‚Ì—v‘f‚Ì’†‚ÅÅ‘å‚Ì“Y‚¦š‚ğ•Ô‚·
// n < min(d) : -1
// max(d) < n : d.size() - 1
int Binary_search(int n, vector<int> &d) {
	auto tag = upper_bound(d.begin(), d.end(), n);
	return distance(d.begin(), tag) - 1;
}

int main(void) {
	int num, m, i, b, ans = INF;
	cin >> num >> m;
	vector<int> a(num);
	rep(i, num)
		cin >> a[i];
	sort(a.begin(), a.end());
	rep(i, m) {
		cin >> b;
		int p = Binary_search(b, a);
		if (0 <= p)
			chmin(ans, abs(a[p] - b));
		if (p + 1 < num)
			chmin(ans, abs(a[p + 1] - b));
	}
	cout << ans << "\n";
	return 0;
}