#include <iostream>
#include <vector>
#include <string>
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
	ll sum = 0, ans, k;
	cin >> num;
	vector<ll> d(num), a(num + 1, 0);
	rep(i, num) {
		cin >> d[i];
		a[d[i]]++;
	}
	rep(i, num + 1)
		sum += a[i] * (a[i] - 1) / 2;
	rep(i, num) {
		k = a[d[i]];
		ans = sum - k * (k - 1) / 2 + (k - 1) * (k - 2) / 2;
		cout << ans << "\n";
	}
	return 0;
}