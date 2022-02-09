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
typedef pair<int, int> pp;

int main(void) {
	int num, i;
	ll k, a, s = 0, ans = 0;
	cin >> num >> k;
	map<ll, int> mp;
	mp[0] = 1;
	rep(i, num) {
		cin >> a;
		s += a;
		ans += mp[s - k];
		mp[s]++;
	}
	cout << ans << "\n";
	return 0;
}