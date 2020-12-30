#include <iostream>
#include <vector>
#include <string>
#include <list>
#include <queue>
#include <set>
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

template <typename T>
class BIT {
	int size;
	vector<T> d;

public:
	BIT(int Size, T Val = 0) {
		size = Size;
		d.resize(size + 1);
		fill(d.begin(), d.end(), Val);
	}
	void add(int pos, T val) {
		while (pos <= size) {
			d[pos] += val;
			pos += pos & -pos;
		}
	}
	T sum(int pos) {
		if (pos == 0)
			return 0;
		T ans = 0;
		while (pos) {
			ans += d[pos];
			pos -= pos & -pos;
		}
		return ans;
	}
	T sum(int l, int r) {
		return sum(r) - sum(l - 1);
	}
};

int main(void) {
	int num, i, h, w, ok = 1;
	ll ans = 0;
	pp L = { 1, INF }, U = { INF, 1 };
	cin >> h >> w >> num;
	vector<pp> d;
	vector<vector<pp>> x(w + 1);
	BIT<int> bit(h);
	rep(i, num) {
		pp a;
		cin >> a.second >> a.first;
		x[a.first].push_back(a);
	}
	if (x[1].size()) {
		sort(x[1].begin(), x[1].end());
		for (int j = x[1][0].second; j <= h; j++)
			bit.add(j, 1);
	}
	for (i = 1; i <= w; i++) {
		if (!ok)
			x[i].push_back({ i, 1 });
		if (x[i].size() == 0) {
			ans += h;
			continue;
		}
		sort(x[i].begin(), x[i].end());
		if (x[i].size() && x[i][0].second == 1)
			ok = 0;
		for (pp& a : x[i]) {
			if (!bit.sum(a.second, a.second))
				bit.add(a.second, 1);
		}
		ans += h - bit.sum(x[i][0].second, h);
	}
	cout << ans << "\n";
	return 0;
}