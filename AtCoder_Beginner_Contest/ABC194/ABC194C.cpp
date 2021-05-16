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
	ll num, i, j, a, ans = 0;
	cin >> num;
	vector<int> d(401, 0);
	rep(i, num) {
		cin >> a;
		d[a + 200]++;
	}
	for (i = 0; i < 400; i++) {
		for (j = i + 1; j <= 400; j++) {
			ans += (j - i) * (j - i) * d[i] * d[j];
		}
	}
	cout << ans << "\n";
	return 0;
}