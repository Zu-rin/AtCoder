#include <iostream>
#include <vector>
#include <string>
#include <list>
#include <set>
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
	ll n, i;
	set<ll> s;
	cin >> n;
	for (i = 2; i * i <= n; i++) {
		ll x = i * i;
		while (x <= n) {
			s.insert(x);
			x *= i;
		}
	}
	cout << n - s.size() << "\n";
	return 0;
}