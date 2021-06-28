#include <iostream>
#include <vector>
#include <string>
#include <list>
#include <queue>
#include <algorithm>
#define rep(i, n) for(i = 0; i < (n); i++)
#define chmay(x, y) x = max(x, y)
#define chmin(x, y) x = min(x, y)
#define MOD 1000000007
#define PI 3.14159265358979323846
#define INF 1 << 30

using namespace std;
typedef long long ll;
typedef pair<int, int> pp;

int main(void) {
	int num, i;
	ll a, b, ans = 0;
	cin >> num;
	vector<ll> x(num), y(num);
	rep(i, num)
		cin >> x[i] >> y[i];
	sort(x.begin(), x.end());
	sort(y.begin(), y.end());
	a = x[num / 2];
	b = y[num / 2];
	rep(i, num)
		ans += abs(a - x[i]) + abs(b - y[i]);
	cout << ans << "\n";
	return 0;
}