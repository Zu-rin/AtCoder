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
	int num, i, m, a, b, ok, ans = 0;
	cin >> num >> m;
	vector<int> d(num);
	vector<list<int>> r(num);
	rep(i, num)
		cin >> d[i];
	rep(i, m) {
		cin >> a >> b;
		a--; b--;
		r[a].push_back(b);
		r[b].push_back(a);
	}
	rep(i, num) {
		ok = true;
		for (auto it = r[i].begin(); it != r[i].end(); it++) {
			if (d[i] <= d[*it]) {
				ok = 0;
				break;
			}
		}
		if (ok)
			ans++;
	}
	cout << ans << "\n";
	return 0;
}