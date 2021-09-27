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
	int i;
	ll num, k = 0, ans = 0, dig = 0, s = 0;
	cin >> num;
	dig = to_string(num).size();
	rep (i, dig - 1) {
		k *= 10;
		k++;
		ans += k;
	}
	k = 1;
	rep(i, dig - 1)
		k *= 10;
	while (k) {
		s += k;
		ans += max(0ll, min(s + k, num + 1) - s);
		k /= 10;
	}
	cout << ans << "\n";
	return 0;
}