#include <iostream>
#include <vector>
#include <string>
#include <list>
#include <map>
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
typedef pair<const int, ll> pp;

int main(void) {
	int i, a;
	ll num, ans = 0;
	map<int, ll> mp;
	cin >> num;
	rep(i, num) {
		cin >> a;
		mp[a]++;
	}
	for (pp& x : mp) {
		ans += x.second * (num - x.second);
	}
	ans >>= 1;
	cout << ans << "\n";
	return 0;
}