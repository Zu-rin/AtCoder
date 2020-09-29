#include <iostream>
#include <vector>
#include <string>
#include <algorithm>
#define rep(i, n) for(i = 0; i < (n); i++)
#define chmax(x, y) x = max(x, y)
#define MOD 1000000007
#define INF 1 << 30

using namespace std;
typedef long long ll;
typedef pair<int, int> pp;

int main(void) {
	int n, m, i, a, ans = 0, b = 0;
	string s;
	cin >> n >> m;
	vector<int> ac(n + 1, 0), wa(n + 1, 0);
	rep(i, m) {
		cin >> a >> s;
		if (ac[a])
			continue;
		if (s == "AC")
			ac[a] = 1;
		else
			wa[a]++;
	}
	rep(i, n + 1) {
		if (ac[i]) {
			ans++;
			b += wa[i];
		}
	}
	cout << ans << " " << b << "\n";
	return 0;
}