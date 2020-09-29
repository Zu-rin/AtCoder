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

class BIT {
	vector<int> d;
	int num;

public:
	BIT(int N) {
		num = N;
		d.resize(N + 1);
		fill(d.begin(), d.end(), 0);
	}

	void add(int p, const int x = 1) {
		while (p <= num) {
			d[p] += x;
			p += p & -p;
		}
	}

	int sum(int p) {
		int ans = 0;
		while (p) {
			ans += d[p];
			p ^= p & -p;
		}
		return ans;
	}
};

int main(void) {
	int num, i, j, a, n = 0;
	cin >> num;
	vector<int> ans(num + 1), k(num), d(num + 1);
	BIT bit(num);
	rep(i, num) {
		scanf("%d", &k[i]);
		scanf("%d", &d[k[i]]);
	}
	a = num;
	for (i = 1; i <= num; i++) {
		bit.add(d[i]);
		n++;
		if (bit.sum(a - n) == 0) {
			rep(j, n)
				ans[i - j] = n;
			a -= n;
			n = 0;
		}
	}
	rep(i, num) {
		cout << ans[k[i]] << "\n";
	}
	return 0;
}