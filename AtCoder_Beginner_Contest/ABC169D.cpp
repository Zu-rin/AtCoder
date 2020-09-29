#include <iostream>
#include <vector>
#include <string>
#include <list>
#include <queue>
#include <cmath>
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

int Bitnum(ll n) {
	int ans = 0;
	while (ans * (ans + 1) / 2 <= n)
		ans++;
	return ans - 1;
}

int main(void) {
	ll num, i, n = 0, ans, lim;
	cin >> num;
	lim = sqrt(num);
	while (!(num & 1)) {
		n++;
		num >>= 1;
	}
	ans = Bitnum(n);
	for (i = 3; i <= min(num, lim); i += 2) {
		n = 0;
		while (num % i == 0) {
			n++;
			num /= i;
		}
		ans += Bitnum(n);
	}
	if (num > 1)
		ans++;
	cout << ans << "\n";
	return 0;
}