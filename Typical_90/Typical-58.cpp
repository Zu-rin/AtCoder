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

int Search(vector<vector<int>> &d, int n, int b) {
	if (d[n][b] >= 0)
		return d[n][b];
	if (b) {
		int p = n;
		for (int i = 0; i < b; i++)
			p = Search(d, p, i);
		return d[n][b] = Search(d, p, 0);
	}
	else {
		int ans = n;
		for (char c : to_string(n))
			ans += c - '0';
		return d[n][0] = ans % 100000;
	}
}

int main(void) {
	int n, i;
	ll k;
	cin >> n >> k;
	vector<vector<int>> d(100000, vector<int>(65, -1));
	for (int i = 0; (1ll << i) <= k; i++) {
		if ((1ll << i) & k) {
			n = Search(d, n, i);
		}
	}
	cout << n << "\n";
	return 0;
}