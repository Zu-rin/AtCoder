#include <iostream>
#include <vector>
#include <string>
#include <list>
#include <cmath>
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
	ll ans = 0, r, x, y;
	cin >> r >> x >> y;
	ll d2 = x * x + y * y;
	ll r2 = r * r;
	while (d2 > ans * ans * r2)
		ans++;
	if (ans == 1 and r2 > d2)
		ans = 2;
	cout << ans << "\n";
	return 0;
}