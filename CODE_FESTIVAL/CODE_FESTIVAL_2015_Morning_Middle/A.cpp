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
	ll num, i, k, ma, r, sum = 0, ans = 0;
	cin >> num >> k >> ma >> r;
	if (num == 1) {
		cout << r << "\n";
		return 0;
	}
	vector<ll> d(num, 0);
	rep(i, num - 1)
		cin >> d[i];
	sort(d.begin(), d.end(), greater<ll>());
	rep(i, k - 1)
		sum += d[i];
	if (sum + d[k - 1] >= r * k)
		printf("0\n");
	else {
		ans = r * k - sum;
		if (ans > ma)
			printf("-1\n");
		else
			cout << ans << "\n";
	}
	return 0;
}