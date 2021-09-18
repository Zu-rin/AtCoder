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
	vector<int> a, b;
	string s, t;
	cin >> num >> s >> t;
	rep(i, num) {
		if (s[i] == '0')
			a.push_back(i);
		if (t[i] == '0')
			b.push_back(i);
	}
	if (a.size() != b.size())
		printf("-1\n");
	else {
		int ans = 0;
		rep(i, a.size()) {
			if (a[i] != b[i])
				ans++;
		}
		cout << ans << "\n";
	}
	return 0;
}