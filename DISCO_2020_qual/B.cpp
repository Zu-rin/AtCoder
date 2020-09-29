#include <iostream>
#include <vector>
#include <string>
#include <algorithm>
#define rep(i, n) for(i = 0; i < (n); i++)
#define chmax(x, y) x = max(x, y)
#define chmin(x, y) x = min(x, y)
#define MOD 1000000007
#define INF 1ll << 60
 
using namespace std;
typedef long long ll;
typedef pair<int, int> pp;
 
int main(void) {
	int num, i;
	ll sum = 0, ans = INF;
	cin >> num;
	vector<ll> d(num);
	rep(i, num) {
		cin >> d[i];
		sum += d[i];
	}
	rep(i, num - 1) {
		d[i + 1] += d[i];
		chmin(ans, abs(sum - 2 * d[i]));
	}
	cout << ans << "\n";
	return 0;
}