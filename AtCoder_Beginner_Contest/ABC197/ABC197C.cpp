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
#define INF 1ll << 60

using namespace std;
typedef long long ll;
typedef pair<int, int> pp;

ll Calc(int v, vector<int> &d) {
	int i, x = 0, ans = 0;
	vector<int> a;
	rep(i, d.size()) {
		if (v & (1 << i)) {
			a.push_back(x);
			x = d[i];
		}
		else {
			x |= d[i];
		}
	}
	a.push_back(x);
	for (int x : a)
		ans ^= x;
	return ans;
}

int main(void) {
	int num, i;
	ll ans = INF;
	cin >> num;
	vector<int> d(num);
	rep(i, num)
		cin >> d[i];
	for (i = 0; i < 1 << num; i += 2) {
		chmin(ans, Calc(i, d));
	}
	cout << ans << "\n";
	return 0;
}