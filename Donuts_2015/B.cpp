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

int Bitnum(int n) {
	int ans = 0;
	while (n > 0) {
		if (n & 1)
			ans++;
		n >>= 1;
	}
	return ans;
}

int Base(int v, vector<int>& d) {
	int i = 0, ans = 0;
	while (v > 0) {
		if (v & 1)
			ans += d[i];
		v >>= 1;
		i++;
	}
	return ans;
}

int Search(int n, int v, vector<int> & d, vector<pp> & cb) {
	if (n == d.size() || Bitnum(v) == 9) {
		int i, ans = Base(v, d);
		rep(i, cb.size()) {
			if (Bitnum(v & cb[i].second) >= 3)
				ans += cb[i].first;
		}
		return ans;
	}
	return max(Search(n + 1, v, d, cb), Search(n + 1, v | (1 << n), d, cb));
}

int main(void) {
	int num, i, j, m, n, a, ans;
	cin >> num >> m;
	vector<int> d(num);
	vector<pp> cb(m);
	rep(i, num)
		cin >> d[i];
	rep(i, m) {
		cin >> cb[i].first >> n;
		cb[i].second = 0;
		rep(j, n) {
			cin >> a;
			cb[i].second |= 1 << (a - 1);
		}
	}
	ans = Search(0, 0, d, cb);
	cout << ans << "\n";
	return 0;
}