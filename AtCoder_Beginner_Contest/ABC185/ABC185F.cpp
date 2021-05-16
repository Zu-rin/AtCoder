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
			d[pos] ^= val;
			pos += pos & -pos;
		}
	}
	T sum(int pos) {
		T ans = 0;
		while (pos) {
			ans ^= d[pos];
			pos -= pos & -pos;
		}
		return ans;
	}
};

int main(void) {
	int num, i, q, t, a, b;
	cin >> num >> q;
	BIT<int> d(num);
	rep(i, num) {
		cin >> a;
		d.add(i + 1, a);
	}
	rep(i, q) {
		cin >> t >> a >> b;
		if (t == 1) {
			d.add(a, b);
		}
		else {
			int ans = d.sum(a - 1) ^ d.sum(b);
			cout << ans << "\n";
		}
	}
	return 0;
}