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
		T ans = 0;
		while (pos) {
			ans += d[pos];
			pos -= pos & -pos;
		}
		return ans;
	}
};

int main(void) {
	ll num, m, ans = 0;
	int i, j = 0;
	cin >> num >> m;
	vector<pp> d(m);
	BIT<int> a(num + 1, 0), b(num + 1, 0);
	rep(i, m)
		cin >> d[i].second >> d[i].first;
	sort(d.begin(), d.end());
	rep(i, m) {
		ans += a.sum(d[i].second - 1) - b.sum(d[i].second) - (b.sum(d[i].first) - b.sum(d[i].first - 1));
		a.add(d[i].second, 1);
		b.add(d[i].first, 1);
	}
	cout << ans << "\n";
	return 0;
}