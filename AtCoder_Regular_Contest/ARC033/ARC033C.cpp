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

template<class T>
class BIT {
	int num;
	vector<T> d;

public:
	BIT(int n, T s) {
		num = n;
		d = vector<T>(num + 1, s);
	}

	T Sum(int p) {
		T ans = 0;
		chmin(p, num);
		while (p) {
			ans += d[p];
			p ^= p & -p;
		}
		return ans;
	}

	void Add(int p, T x) {
		while (p <= num) {
			d[p] += x;
			p += p & -p;
		}
	}

	int size() {
		return num;
	}
};

int Search(int x, BIT<int>& d) {
	int l = 0, r = d.size(), p;
	while (l != r) {
		p = (l + r) >> 1;
		if (x <= d.Sum(p))
			r = p;
		else
			l = p + 1;
	}
	return l;
}

int main(void) {
	int num, i, k, x;
	BIT<int> d(200000, 0);
	cin >> num;
	rep(i, num) {
		scanf("%d%d", &k, &x);
		if (k == 1) {
			d.Add(x, 1);
		}
		else {
			int ans = Search(x, d);
			cout << ans << "\n";
			d.Add(ans, -1);
		}
	}
	return 0;
}