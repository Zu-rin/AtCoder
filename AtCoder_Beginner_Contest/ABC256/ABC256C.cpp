#include <iostream>
#include <vector>
#include <string>
#include <list>
#include <set>
#include <map>
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

vector<int> h(3), w(3), d(4);

int Search(int k = 0) {
	if (k < d.size()) {
		int ans = 0;
		for (d[k] = 1; d[k] <= 30; d[k]++) {
			ans += Search(k + 1);
		}
		return ans;
	}
	int i;
	vector<vector<int>> x(3, vector<int>(3));
	rep(i, d.size())
		x[i / 2][i % 2] = d[i];
	rep(i, 2) {
		if ((x[i][2] = h[i] - x[i][0] - x[i][1]) < 1)
			return 0;
	}
	rep(i, 3) {
		if ((x[2][i] = w[i] - x[0][i] - x[1][i]) < 1)
			return 0;
	}
	int a = 0, b = 0;
	rep(i, 3) {
		a += x[i][2];
		b += x[2][i];
	}
	if (a == w[2] and b == h[2])
		return 1;
	return 0;
}

int main(void) {
	int num, i;
	rep(i, 3)
		cin >> h[i];
	rep(i, 3)
		cin >> w[i];
	cout << Search() << "\n";
	return 0;
}