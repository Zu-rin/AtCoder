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
	ll ans = 0;
	string s;
	vector<int> d(26, 0);
	cin >> s;
	reverse(s.begin(), s.end());
	rep(i, s.size() - 1) {
		if (s[i] == s[i + 1]) {
			ans += i - d[s[i] - 'a'];
			fill(d.begin(), d.end(), 0);
			d[s[i] - 'a'] = i;
		}
		d[s[i] - 'a']++;
	}
	cout << ans << "\n";
	return 0;
}