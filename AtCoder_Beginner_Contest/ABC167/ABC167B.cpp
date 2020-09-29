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

ll Ans(ll a, ll b, ll c, ll num) {
	ll ans = min(a, num);
	num -= a + b;
	if (num <= 0)
		return ans;
	return ans - num;
}

int main(void) {
	ll a, b, c, num, ans;
	cin >> a >> b >> c >> num;
	cout << Ans(a, b, c, num) << "\n";
	return 0;
}