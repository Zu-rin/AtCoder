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
	int n, m, i, j;
	cin >> n >> m;
	vector<int> a(n + 1), b(m + 1), c(n + m + 1);
	rep(i, a.size())
		cin >> a[i];
	rep(i, c.size())
		cin >> c[i];
	for (i = m; i >= 0; i--) {
		for (j = min(m, i + n); j > i; j--)
			c[n + i] -= a[n + i - j] * b[j];
		b[i] = c[n + i] / a[n];
	}
	rep(i, b.size() - 1)
		cout << b[i] << " ";
	cout << b[i] << "\n";
	return 0;
}