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

int n, m, k;

int Judge(int v, vector<pp> & a, vector<pp> & x) {
	int i, ans = 0;
	vector<char> d(n + 1, 0);
	rep(i, k)
		d[v & (1 << i) ? x[i].first : x[i].second] = 1;
	for (pp& p : a) {
		if (d[p.first] && d[p.second])
			ans++;
	}
	return ans;
}

int main(void) {
	int i, ans = 0;
	cin >> n >> m;
	vector<pp> a(m);
	rep(i, m)
		cin >> a[i].first >> a[i].second;
	cin >> k;
	vector<pp> x(k);
	rep(i, k)
		cin >> x[i].first >> x[i].second;
	rep(i, 1 << k)
		chmax(ans, Judge(i, a, x));
	cout << ans << "\n";
	return 0;
}