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
	int num, i;
	ll n, ans = 0, k = 1;
	cin >> n;
	while (n > 0) {
		ans += k;
		n >>= 1;
		k <<= 1;
	}
	cout << ans << "\n";
	return 0;
}