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

ll Div(ll n) {
	if (n == 1)
		return 0;
	ll i, ans = 1;
	for (i = 2; i * i < n; i++) {
		if (n % i == 0)
			ans += 2;
	}
	if (i * i == n)
		ans++;
	return ans;
}

int Isok(ll n, ll k) {
	while (n % k == 0)
		n /= k;
	return n % k == 1;
}

int main(void) {
	ll num, i, ans = 1;
	cin >> num;
	ans += Div(num - 1);
	for (i = 2; i * i < num; i++) {
		if (num % i == 0) {
			ans += Isok(num, i);
			ans += Isok(num, num / i);
		}
	}
	if (i * i == num)
		ans += Isok(num, i);
	cout << ans << "\n";
	return 0;
}