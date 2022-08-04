#include <iostream>
#include <vector>
#include <string>
#include <list>
#include <set>
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
	int num, i, k;
	map<int, int> mp;
	cin >> num >> k;
	vector<int> d(num), ans(num + 1, -1), a(num + 1, -1);
	rep(i, num) {
		cin >> d[i];
		auto it = mp.lower_bound(d[i]);
		if (it == mp.end())
			mp[d[i]] = 1;
		else {
			a[d[i]] = (*it).first;
			mp[d[i]] = (*it).second + 1;
			mp.erase(it);
		}
		if (mp[d[i]] == k) {
			mp.erase(d[i]);
			int n = d[i];
			while (n >= 0) {
				ans[n] = i + 1;
				n = a[n];
			}
		}
	}
	for(i = 1; i <= num; i++)
		cout << ans[i] << "\n";
	return 0;
}