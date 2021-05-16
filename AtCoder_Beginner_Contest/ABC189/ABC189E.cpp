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
typedef struct {
	ll x, y;
} point;
typedef struct Query{
	int a, b, i;
	friend bool operator<(Query& l, Query& r) {
		return l.a < r.a;
	}
} query;

struct Trans {
	struct Weights {
		ll a, b, c;
		Weights() {
			a = b = c = 0;
		}
		Weights operator*(ll r) {
			Weights ans;
			ans.a = this->a * r;
			ans.b = this->b * r;
			ans.c = this->c * r;
			return ans;
		}
	};
	int count;
	Weights x, y;
	Trans() {
		count = 0;
		x.a = y.b = 1;
	}
	point Calc(point p) {
		point ans;
		ans.x = x.a * p.x + x.b * p.y + x.c;
		ans.y = y.a * p.x + y.b * p.y + y.c;
		return ans;
	}
	void step(pp op) {
		count++;
		if (op.first == 1) {
			swap(x, y);
			y = y * -1;
		}
		else if (op.first == 2) {
			swap(x, y);
			x = x * -1;
		}
		else if (op.first == 3) {
			x = x * -1;
			x.c += op.second * 2;
		}
		else {
			y = y * -1;
			y.c += op.second * 2;
		}
	}
};

int main(void) {
	int num, m, q, i;
	cin >> num;
	vector<point> d(num);
	rep(i, num)
		cin >> d[i].x >> d[i].y;
	cin >> m;
	vector<pp> op(m);
	rep(i, m) {
		cin >> op[i].first;
		if (op[i].first > 2)
			cin >> op[i].second;
	}
	cin >> q;
	vector<point> ans(q);
	vector<query> querys(q);
	Trans t;
	rep(i, q) {
		cin >> querys[i].a >> querys[i].b;
		querys[i].b--;
		querys[i].i = i;
	}
	sort(querys.begin(), querys.end());
	for (query qr : querys) {
		while (t.count < qr.a) {
			t.step(op[t.count]);
		}
		ans[qr.i] = t.Calc(d[qr.b]);
	}
	for (point p : ans) {
		cout << p.x << " ";
		cout << p.y << "\n";
	}
	return 0;
}