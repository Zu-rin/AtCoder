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
	int num, m, q, i, j, k, a, b;
	cin >> num >> m >> q;
	vector<int> d(m + 1, num);
	vector<vector<int>> cl(num + 1, vector<int>(m + 1, false));
	d[0] = 0;
	rep(i, q) {
		cin >> k >> a;
		if (k == 1) {
			int ans = 0;
			rep(j, m + 1) {
				if (cl[a][j])
					ans += d[j];
			}
			cout << ans << "\n";
		}
		else {
			cin >> b;
			cl[a][b] = true;
			d[b]--;
		}
	}
	return 0;
}