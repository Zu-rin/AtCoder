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

ll Sum(ll s, ll e) {
	return (s + e) * (e / s) / 2;
}

int main(void) {
	ll num, i, ans = 0;
	cin >> num;
	for (i = 1; i <= num; i++) {
		ans += Sum(i, num / i * i);
	}
	cout << ans << "\n";
	return 0;
}