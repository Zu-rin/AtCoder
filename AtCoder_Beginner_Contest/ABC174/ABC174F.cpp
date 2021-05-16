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
typedef struct Query {
	int l, r, i;
	friend bool operator<(Query& l, Query& r) {
		return  l.r < r.r;
	}
} query;
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
	int num, q, i, pos = 0;
	cin >> num >> q;
	vector<int> d(num), v(num + 1, 0), ans(q);
	vector<query> qr(q);
	BIT<int> bit(num);
	rep(i, num)
		cin >> d[i];
	rep(i, q) {
		cin >> qr[i].l >> qr[i].r;
		qr[i].i = i;
	}
	sort(qr.begin(), qr.end());
	for (query& a : qr) {
		while (pos < a.r) {
			if (v[d[pos]])
				bit.add(v[d[pos]], -1);
			bit.add(pos + 1, 1);
			v[d[pos]] = pos + 1;
			pos++;
		}
		ans[a.i] = bit.sum(a.r) - bit.sum(a.l - 1);
	}
	rep(i, q)
		cout << ans[i] << "\n";
	return 0;
}