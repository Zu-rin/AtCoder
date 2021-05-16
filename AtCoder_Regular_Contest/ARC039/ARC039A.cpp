#include <iostream>
#include <vector>
#include <string>
#include <algorithm>
#define rep(i, n) for(i = 0; i < (n); i++)
#define chmax(x, y) x = max(x, y)
#define chmin(x, y) x = min(x, y)
#define MOD 1000000007
#define INF 1 << 30

using namespace std;
typedef long long ll;
typedef pair<int, int> pp;

int main(void) {
	int num, i, ans = -INF;
	vector<int> a(4), b(4);
	cin >> a[0] >> b[0];
	a[1] = a[0] % 100 + 900;
	b[1] = b[0] % 100 + 100;
	a[2] = a[0] - (a[0] % 100) / 10 * 10 + 90;
	b[2] = b[0] - (b[0] % 100) / 10 * 10;
	a[3] = a[0] - (a[0] % 10) + 9;
	b[3] = b[0] - (b[0] % 10);
	for (i = 1; i <= 3; i++) {
		chmax(ans, a[0] - b[i]);
		chmax(ans, a[i] - b[0]);
	}
	cout << ans << "\n";
	return 0;
}