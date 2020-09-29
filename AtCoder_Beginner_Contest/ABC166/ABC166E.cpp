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
	int num, i;
	ll ans = 0;
	cin >> num;
	vector<int> d(num);
	map<int, int> mp;
	rep(i, num) {
		cin >> d[i];
		mp[i - d[i]]++;
		d[i] += i;
	}
	rep(i, num) {
		ans += mp[d[i]];
	}
	cout << ans << "\n";
	return 0;
}