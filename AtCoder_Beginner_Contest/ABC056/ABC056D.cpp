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

int num, k;

char Judge(int p, vector<ll> & d) {
	int i, j;
	vector<char> a(k, 0);
	a[0] = 1;
	for (i = 0; i < d.size(); i++) {
		if (i == p)
			continue;
		for (j = k - 1; j >= d[i]; j--) {
			if (a[j - d[i]])
				a[j] = 1;
		}
	}
	for (j = max(0ll, k - d[p]); j < k; j++) {
		if (a[j])
			return 1;
	}
	return 0;
}

int Search(int l, int r, vector<ll>& d) {
	if (r - l == 1)
		return r;
	int p = (l + r) / 2;
	if (Judge(p, d))
		return Search(l, p, d);
	return Search(p, r, d);
}

int main(void) {
	int i, j, ans = 0;
	cin >> num >> k;
	vector<ll> d(num);
	vector<vector<char>> a(num + 1, vector<char>(k, 0));
	a[0][0] = 1;
	rep(i, num)
		cin >> d[i];
	sort(d.begin(), d.end());
	rep(i, num) {
		rep(j, k) {
			if (a[i][j]) {
				a[i + 1][j] = 1;
				if (d[i] + j < k)
					a[i + 1][d[i] + j] = 1;
			}
		}
	}
	cout << Search(-1, num, d) << "\n";
	return 0;
}