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

int main(void) {
	int num, i, j, k, a, b;
	ll ans = 0;
	string s, rgb = "RGB";
	cin >> num >> s;
	vector<vector<ll>> d(3, vector<ll>(num, 0));
	rep(i, num) {
		d[rgb.find(s[i])][i]++;
	}
	rep(i, num - 1) {
		rep(j, 3) {
			d[j][i + 1] += d[j][i];
		}
	}
	rep(j, num) {
		b = rgb.find(s[j]);
		rep(i, j) {
			if (s[i] == s[j])
				continue;
			a = b + (int)rgb.find(s[i]) - 1;
			if (a == 0)
				a = 2;
			else if (a == 2)
				a = 0;
			ans += d[a][num - 1] - d[a][j];
			k = j + j - i;
			if (k < num && s[k] == rgb[a])
				ans--;
		}
	}
	cout << ans << "\n";
	return 0;
}