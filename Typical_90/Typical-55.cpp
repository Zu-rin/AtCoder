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

ll p, q;

ll Solver(vector<ll> &d, ll pro = 1, int s = 0, int dep = 0) {
	if (dep == 5)
		return pro == q;
	ll ans = 0;
	for (int i = s; i < d.size(); i++) {
		ans += Solver(d, pro * d[i] % p, i + 1, dep + 1);
	}
	return ans;
}

int main(void) {
	int num, i;
	cin >> num >> p >> q;
	vector<ll> d(num);
	rep(i, num)
		cin >> d[i];
	cout << Solver(d) << "\n";
	return 0;
}