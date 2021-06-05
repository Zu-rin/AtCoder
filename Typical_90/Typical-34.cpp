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
	int num, k, i, l, r, ans;
	l = r = ans = 0;
	cin >> num >> k;
	vector<int> d(num);
	map<int, int> mp;
	rep(i, num)
		cin >> d[i];
	while (r < num) {
		mp[d[r++]]++;
		while (mp.size() > k) {
			if (mp[d[l]] == 1)
				mp.erase(d[l]);
			else
				mp[d[l]]--;
			l++;
		}
		chmax(ans, r - l);
	}
	cout << ans << "\n";
	return 0;
}