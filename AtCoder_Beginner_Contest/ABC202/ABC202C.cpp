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
	int num, i, a, b, c;
	ll ans = 0;
	cin >> num;
	map<int, int> mp;
	vector<int> k(num + 1);
	vector<vector<int>> d(num + 1);
	rep(i, num) {
		cin >> a;
		mp[a]++;
	}
	for (i = 1; i <= num; i++) {
		cin >> b;
		d[b].push_back(i);
	}
	rep(i, num) {
		cin >> c;
		k[c]++;
	}
	for(auto it = mp.begin(); it != mp.end(); it++) {
		int a = (*it).first;
		for (int b : d[a]) {
			ans += (ll)k[b] * (*it).second;
		}
	}
	cout << ans << "\n";
	return 0;
}