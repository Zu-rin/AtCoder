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
	int num, i;
	ll k = 0;
	string s, ans = "";
	cin >> s;
	vector<int> d(s.size(), 0);
	d[0] = s[0] - '0';
	for (i = 1; i < s.size(); i++)
		d[i] = d[i - 1] + s[i] - '0';
	for (i = s.size() - 1; i >= 0; i--) {
		k += d[i];
		ans += '0' + (k % 10);
		k /= 10;
	}
	while (k) {
		ans += '0' + (k % 10);
		k /= 10;
	}
	reverse(ans.begin(), ans.end());
	cout << ans << "\n";
	return 0;
}