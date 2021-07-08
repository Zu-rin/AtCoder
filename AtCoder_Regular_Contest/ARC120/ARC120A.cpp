#include <iostream>
#include <vector>
#include <string>
#include <list>
#include <queue>
#include <algorithm>
#define rep(i, n) for(i = 0; i < (n); i++)
#define chmax(x, y) x = max(x, y)
#define chmin(x, y) x = min(x, y)
#define MOD 998244353
#define PI 3.14159265358979323846
#define INF 1 << 30

using namespace std;
typedef long long ll;
typedef pair<int, int> pp;

int main(void) {
	int num, i, h, w;
	ll ans = 1;
	cin >> h >> w;
	vector<string> s(h);
	rep(i, h)
		cin >> s[i];
	rep(i, h + w - 1) {
		char c = '.';
		for (int a = max(0, i - w + 1), b = i - a; a < h and 0 <= b; a++, b--) {
			if (s[a][b] != '.') {
				if (c == '.')
					c = s[a][b];
				else if (c != s[a][b]) {
					ans = 0;
					break;
				}
			}
		}
		if (c == '.') {
			ans *= 2;
			ans %= MOD;
		}
	}
	cout << ans << "\n";
	return 0;
}