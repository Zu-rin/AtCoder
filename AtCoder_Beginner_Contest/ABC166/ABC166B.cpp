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
	int num, i, q, j, n, a, ans= 0;
	cin >> num >> q;
	vector<int> d(num + 1, true);
	d[0] = 0;
	rep(j, q) {
		cin >> n;
		rep(i, n) {
			cin >> a;
			d[a] = 0;
		}
	}
	rep(i, num + 1) {
		if (d[i])
			ans++;
	}
	cout << ans << "\n";
	return 0;
}