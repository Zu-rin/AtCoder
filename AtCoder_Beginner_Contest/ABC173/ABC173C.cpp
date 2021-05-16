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

int Search(int a, int b, vector<string> & s) {
	int i, j, ans = 0;
	rep(i, s.size()) {
		if (a & (1 << i))
			continue;
		rep(j, s[i].size()) {
			if (b & (1 << j))
				continue;
			if (s[i][j] == '#')
				ans++;
		}
	}
	return ans;
}

int main(void) {
	int num, i, j, h, w, k;
	ll ans = 0;
	cin >> h >> w >> k;
	vector<string> s(h);
	rep(i, h)
		cin >> s[i];
	rep(i, 1 << h) {
		rep(j, 1 << w) {
			if (Search(i, j, s) == k)
				ans++;
		}
	}
	cout << ans << "\n";
	return 0;
}