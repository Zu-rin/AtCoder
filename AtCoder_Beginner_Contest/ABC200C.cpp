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
	int num, i, a;
	ll ans = 0;
	cin >> num;
	vector<vector<int>> d;
	rep(i, num) {
		int nw = 1;
		cin >> a;
		for (auto& l : d) {
			if (abs(l[0] - a) % 200 == 0) {
				l.push_back(a);
				nw = 0;
				break;
			}
		}
		if (nw) {
			d.push_back({ a });
		}
	}
	for (auto& l : d) {
		ll len = l.size();
		ans += len * (len - 1) / 2;
	}
	cout << ans << "\n";
	return 0;
}