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
	int num, i, k = 0;
	map<int, int> mp;
	cin >> num;
	vector<int> d(num), ans(num, 0);
	rep(i, num) {
		cin >> d[i];
		mp[d[i]] = 0;
	}
	for (auto it = mp.rbegin(); it != mp.rend(); it++) {
		(*it).second = k++;
	}
	rep(i, num) {
		ans[mp[d[i]]]++;
	}
	rep(i, num) {
		cout << ans[i] << "\n";
	}
	return 0;
}