#include <iostream>
#include <vector>
#include <string>
#include <list>
#include <queue>
#include <map>
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
	int num, i, x, a, ans;
	map<int, int> mp;
	cin >> x >> num;
	rep(i, num) {
		cin >> a;
		mp[a];
	}
	rep(i, 51) {
		if (!mp.count(x - i)) {
			ans = x - i;
			break;
		}
		if (!mp.count(x + i)) {
			ans = x + i;
			break;
		}
	}
	cout << ans << "\n";
	return 0;
}