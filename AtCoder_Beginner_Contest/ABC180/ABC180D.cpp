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
	int num, i;
	ll x, y, a, b, sum = 0, ans = 0;
	cin >> x >> y >> a >> b;
	ans = (y - x - 1) / b;
	while (x <= b / (a - 1)) {
		if (y / a <= x)
			break;
		sum++;
		x *= a;
		chmax(ans, sum + (y - x - 1) / b);
	}
	cout << ans << "\n";
	return 0;
}