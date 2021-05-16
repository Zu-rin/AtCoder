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

void Brute(vector<int> & a, vector<int> & x) {
	int i;
	x.resize(1 << a.size());
	x[0] = 0;
	rep(i, a.size()) {
		x[1 << i] = a[i];
	}
	rep(i, x.size()) {
		x[i] = x[i - (i & -i)] + x[i & -i];
	}
	return;
}

// nˆÈ‰º‚Ì—v‘f‚Ì’†‚ÅÅ‘å‚Ì“Y‚¦Žš‚ð•Ô‚·
// n < min(d) : -1
// max(d) < n : d.size() - 1
int Binary_search(int n, vector<int>& d) {
	auto tag = upper_bound(d.begin(), d.end(), n);
	return distance(d.begin(), tag) - 1;
}

int main(void) {
	int num, i, m, ans = 0;
	cin >> num >> m;
	vector<int> a(num >> 1), b(num - (num >> 1)), x, y;
	rep(i, a.size())
		cin >> a[i];
	rep(i, b.size())
		cin >> b[i];
	Brute(a, x);
	Brute(b, y);
	sort(x.begin(), x.end());
	rep(i, y.size()) {
		ans += Binary_search(m - y[i], x) - Binary_search(m - y[i] - 1, x);
	}
	cout << ans << "\n";
	return 0;
}