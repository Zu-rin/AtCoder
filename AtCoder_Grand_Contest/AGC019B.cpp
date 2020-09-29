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
	int i;
	ll num, ans = 0;
	string s;
	vector<ll> d(26, 0);
	cin >> s;
	num = s.size();
	rep(i, s.size())
		d[s[i] - 'a']++;
	rep(i, 26)
		ans += d[i] * (num - d[i]);
	ans >>= 1;
	cout << ans + 1 << "\n";
	return 0;
}