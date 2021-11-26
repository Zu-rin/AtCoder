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
	ll num, i, j, ans = 0;
	cin >> num;
	for (ll i = 1; i * i * i <= num; i++) {
		for (ll j = i; i * j * j <= num; j++) {
			ans += num / (i * j) - j + 1;
		}
	}
	cout << ans << "\n";
	return 0;
}