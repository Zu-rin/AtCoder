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
	ll w, h, num, i, ans;
	cin >> h >> w;
	ans = (h / 2) * w;
	if (h & 1)
		ans += (w / 2) + (w & 1);
	if (w == 1 || h == 1)
		ans = 1;
	cout << ans << "\n";
	return 0;
}