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

int main(void) {
	int num, i, j, h, w, ans = 0;
	cin >> h >> w;
	vector<vector<int>> d(h, vector<int>(w, 0));
	rep(i, h) {
		string s;
		cin >> s;
		rep(j, w)
			d[i][j] = s[j] == '#';
	}
	rep(i, h - 1) {
		rep(j, w - 1) {
			int k = d[i][j] + d[i + 1][j] + d[i][j + 1] + d[i + 1][j + 1];
			if (k == 1 || k == 3)
				ans++;
		}
	}
	cout << ans << "\n";
	return 0;
}