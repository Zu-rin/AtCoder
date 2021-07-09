#include <iostream>
#include <vector>
#include <string>
#include <list>
#include <map>
#include <queue>
#include <algorithm>
#define rep(i, n) for(i = 0; i < (n); i++)
#define chmax(x, y) x = max(x, y)
#define chmin(x, y) x = min(x, y)
#define MOD 1000000007
#define PI 3.14159265358979323846
#define INF 1ll << 60

using namespace std;
typedef long long ll;
typedef pair<int, int> pp;

void dif(vector<ll> &a, vector<ll> &b, ll &mi) {
	int i = 0, j = 0;
	while (i < a.size() and j < b.size()) {
		chmin(mi, abs(a[i] - b[j]));
		a[i] < b[j] ? i++ : j++;
	}
}

int main(void) {
	int num, i;
	ll a, ans = INF, mi[3] = { INF, INF, INF };
	char c;
	string rgb = "RGB";
	vector<ll> d[3];
	cin >> num;
	rep(i, 2 * num) {
		cin >> a >> c;
		d[rgb.find(c)].push_back(a);
	}
	if (!((d[0].size() | d[1].size() | d[2].size()) & 1)) {
		printf("0\n");
		return 0;
	}
	rep(i, 3)
		sort(d[i].begin(), d[i].end());
	rep(i, 3)
		dif(d[i], d[(i + 1) % 3], mi[i]);
	rep(i, 3) {
		int j = (i + 1) % 3;
		int k = (i + 2) % 3;
		if (d[i].size() & d[j].size() & 1) {
			ans = min(mi[i], mi[j] + mi[k]);
			break;
		}
	}
	cout << ans << "\n";
	return 0;
}