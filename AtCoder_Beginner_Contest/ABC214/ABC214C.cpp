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
#define INF 1ll << 60

using namespace std;
typedef long long ll;
typedef pair<int, int> pp;

int main(void) {
	int num, i, s = 0;
	cin >> num;
	vector<ll> a(num), ans(num);
	rep(i, num)
		cin >> a[i];
	rep(i, num) {
		cin >> ans[i];
		if (ans[i] < ans[s])
			s = i;
	}
	for (i = s; (i + 1) % num != s; i = (i + 1) % num)
		chmin(ans[(i + 1) % num], ans[i] + a[i]);
	rep(i, num)
		cout << ans[i] << "\n";
	return 0;
}