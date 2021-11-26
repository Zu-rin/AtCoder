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

ll Search(int n, vector<int> &ng, vector<ll> &a, vector<vector<int>> &d) {
	if (ng[n])
		return 0;
	ng[n] = 1;
	if (d[n].size() == 0)
		return a[n];
	ll ans = a[n];
	for (int nx : d[n]) {
		ans += Search(nx - 1, ng, a, d);
	}
	return ans;
}

int main(void) {
	int num, i, j, k, x;
	cin >> num;
	vector<int> ng(num, 0);
	vector<ll> a(num);
	vector<vector<int>> d(num);
	rep(i, num) {
		cin >> a[i] >> k;
		rep(j, k) {
			cin >> x;
			d[i].push_back(x);
		}
	}
	cout << Search(num - 1, ng, a, d) << "\n";
	return 0;
}