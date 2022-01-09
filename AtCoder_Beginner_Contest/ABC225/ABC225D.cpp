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
	int num, q, i, j, k, a, b;
	cin >> num >> q;
	vector<pp> d(num + 1, pp(0, 0));
	rep(i, q) {
		cin >> k >> a;
		if (k == 1) {
			cin >> b;
			d[a].second = b;
			d[b].first = a;
		}
		else if (k == 2) {
			cin >> b;
			d[a].second = d[b].first = 0;
		}
		else {
			vector<int> ans;
			while (d[a].first)
				a = d[a].first;
			while (a) {
				ans.push_back(a);
				a = d[a].second;
			}
			cout << ans.size() << " ";
			rep(j, ans.size() - 1)
				cout << ans[j] << " ";
			cout << ans[j] << "\n";
		}
	}
	return 0;
}