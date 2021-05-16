#include <iostream>
#include <vector>
#include <string>
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

int Cut(int n, int k, vector<string> & s) {
	int i, j, c = 0, ans = 0;
	vector<vector<int>> d(s.size(), vector<int>(s[0].size(), 0));
	vector<int> a(s.size());
	rep(i, s.size()) {
		a[i] = ans;
		if (n & (1 << i))
			ans++;
	}
	rep(j, s[0].size()) {
		rep(i, s.size()) {
			if (s[i][j] == '1') {
				if (c >= s[0].size())
					return INF;
				if (d[a[i]][c] == k) {
					c++;
					j--;
					break;
				}
				d[a[i]][c]++;
			}
		}
	}
	return ans + c;
}

int main(void) {
	int num, i, h, w, k, ans = INF;
	cin >> h >> w >> k;
	vector<string> s(h);
	rep(i, h)
		cin >> s[i];
	rep(i, 1 << (h - 1)) {
		chmin(ans, Cut(i, k, s));
	}
	cout << ans << "\n";
	return 0;
}