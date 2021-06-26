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

ll Step(ll n) {
	ll ans = 0, k = 1;
	while (n) {
		ans += (n % 9 == 8 ? 5 : n % 9) * k;
		n /= 9;
		k *= 8;
	}
	return ans;
}

int main(void) {
	ll a = 1, n = 0, b = 1, ans = 0;
	string s;
	int i, k;
	cin >> s >> k;
	for(i = s.size() - 1; 0 <= i; i--) {
		n += (s[i] - '0') * a;
		a *= 8;
	}
	rep(i, k)
		n = Step(n);
	while (n) {
		ans += (n % 8) * b;
		n /= 8;
		b *= 10;
	}
	cout << ans << "\n";
	return 0;
}