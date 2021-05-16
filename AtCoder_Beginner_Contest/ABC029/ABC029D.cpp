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
	ll num, i, ans = 0;
	cin >> num;
	for (i = 10; i <= 1000000000; i *= 10) {
		ans += num / i * (i / 10);
		ans += min(max(0ll, num % i - (i / 10) + 1), i / 10);
	}
	cout << ans << "\n";
	return 0;
}