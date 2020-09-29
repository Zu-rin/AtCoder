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
	int n, p, ans;
	ll num, i, k;
	cin >> num >> k;
	vector<int> d(num), a(num, INF), r(num);
	rep(i, num) {
		cin >> d[i];
		d[i]--;
	}
	p = n = 0;
	while (a[n] == INF) {
		if (p == k) {
			cout << n + 1 << "\n";
			return 0;
		}
		a[n] = p++;
		n = d[n];
	}
	k -= a[n];
	p -= a[n];
	k %= p;
	ans = n;
	rep(i, k) {
		ans = d[ans];
	}
	cout << ans + 1 << "\n";
	return 0;
}