#include <iostream>
#include <vector>
#include <string>
#include <algorithm>
#define rep(i, n) for(i = 1; i < (n); i++)
#define chmax(x, y) x = max(x, y)
#define chmin(x, y) x = min(x, y)
#define MOD 1000000007
#define PI 3.14159265358979323846
#define INF 1 << 30

using namespace std;
typedef long long ll;
typedef pair<int, int> pp;

ll gcd(ll a, ll b) {
	if (b == 0)
		return a;
	return gcd(b, a % b);
}

int main(void) {
	ll num, i, j, k, ans = 0, a;
	cin >> num;
	num++;
	rep(i, num) {
		rep(j, num) {
			a = gcd(i, j);
			rep(k, num) {
				ans += gcd(a, k);
			}
		}
	}
	cout << ans << "\n";
	return 0;
}