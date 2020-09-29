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
	ll num, i, ans = 0;
	cin >> num;
	rep(i, num + 1) {
		if (i % 3 == 0 || i % 5 == 0)
			continue;
		ans += i;
	}
	cout << ans << "\n";
	return 0;
}