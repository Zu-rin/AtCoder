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

void AllSum(vector<vector<int>> & d) {
	int i, j;
	rep(i, d.size()) {
		rep(j, d[i].size() - 1)
			d[i][j + 1] += d[i][j];
	}
	rep(j, d[0].size()) {
		rep(i, d.size() - 1)
			d[i + 1][j] += d[i][j];
	}
	return;
}

int main(void) {
	int num, i, j, k, kk, a, b, ans = 0, sum;
	char c;
	cin >> num >> k;
	kk = k << 1;
	vector<vector<int>> d(k, vector<int>(kk, 0));
	rep(i, num) {
		cin >> a >> b >> c;
		if (c == 'W')
			a += k;
		a %= kk;
		b %= kk;
		if (a >= k) {
			a -= k;
			b += k;
			b %= kk;
		}
		d[a][b]++;
	}
	AllSum(d);
	rep(i, k) {
		rep(j, k) {
			sum = (d[i][j] << 1) + d[k - 1][j + k] - d[i][j + k] - d[k - 1][j];
			if (j < k - 1)
				sum += d[i][kk - 1] - d[i][j + k];
			chmax(ans, sum);
			chmax(ans, num - sum);
		}
	}
	cout << ans << "\n";
	return 0;
}