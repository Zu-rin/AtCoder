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
#define INF 1 << 30

using namespace std;
typedef long long ll;
typedef pair<int, int> pp;

int main(void) {
	int num, i, a, q, l, r, x;
	cin >> num;
	vector<map<int, int>> st(num + 1);
	for (i = 1; i <= num; i++) {
		cin >> a;
		st[a][i] = st[a].size();
	}
	cin >> q;
	rep(i, q) {
		cin >> l >> r >> x;
		auto L = st[x].lower_bound(l);
		auto R = st[x].lower_bound(r + 1);
		int ans = (R != st[x].end() ? (*R).second : st[x].size()) - (L != st[x].end() ? (*L).second : st[x].size());
		cout << ans << "\n";
	}
	return 0;
}