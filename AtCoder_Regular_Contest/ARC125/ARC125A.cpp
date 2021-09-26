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
	int num, m, i, ans = 0, s;
	cin >> num >> m;
	vector<int> a(num), b(m), ng(2, 1);
	rep(i, num) {
		cin >> a[i];
		ng[a[i]] = 0;
	}
	rep(i, m) {
		cin >> b[i];
		if (ng[b[i]]) {
			printf("-1\n");
			return 0;
		}
	}
	s = distance(a.begin(), find(a.begin(), a.end(), (a[0] + 1) & 1));
	chmin(s, (int)distance(a.rbegin(), find(a.rbegin(), a.rend(), (a[0] + 1) & 1)) + 1);
	rep(i, m - 1) {
		if (b[i] != b[i + 1])
			ans++;
	}
	if (ans || a[0] != b[0]) {
		ans += s;
		if (a[0] == b[0])
			ans--;
	}
	cout << ans + b.size() << "\n";
	return 0;
}