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

int Search(int n, vector<vector<int>> &d, vector<int> &ok) {
	int ans = 1;
	ok[n] = 0;
	for (int nx : d[n]) {
		if(ok[nx])
			ans += Search(nx, d, ok);
	}
	return ans;
}

int main(void) {
	int num, m, i, a, b, ans = 0;
	cin >> num >> m;
	vector<vector<int>> d(num + 1);
	rep(i, m) {
		cin >> a >> b;
		d[a].push_back(b);
	}
	for (i = 1; i <= num; i++) {
		vector<int> ok(num + 1, 1);
		ans += Search(i, d, ok);
	}
	cout << ans << "\n";
	return 0;
}