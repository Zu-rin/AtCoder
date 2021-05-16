#include <iostream>
#include <vector>
#include <string>
#include <algorithm>
#define rep(i, n) for(i = 0; i < (n); i++)
#define chmax(x, y) x = max(x, y)
#define chmin(x, y) x = min(x, y)
#define MOD 1000000007
#define INF 1 << 30

using namespace std;
typedef long long ll;
typedef pair<int, int> pp;

int main(void) {
	int num, i, p = 0, k = 0, ans = 0;
	string s;
	cin >> s;
	vector<int> d(26, 0);
	rep(i, s.size())
		d[s[i] - 'a']++;
	rep(i, 26) {
		if (d[i] & 1)
			k++;
		p += d[i] >> 1;
	}
	if (k)
		ans = p / k * 2 + 1;
	else
		ans = s.size();
	cout << ans << "\n";
	return 0;
}