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
	int num, i, k;
	ll ans = 0;
	cin >> num >> k;
	vector<int> d(num);
	rep(i, num)
		cin >> d[i];
	sort(d.begin(), d.end());
	rep(i, num - k)
		ans += (ll)d[i];
	cout << ans << "\n";
	return 0;
}