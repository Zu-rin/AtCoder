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
	int i, t;
	ll ans, num;
	vector<char> d(200, 1);
	vector<ll> a;
	cin >> t >> num;
	t += 100;
	for (i = 1; i <= t; i++) {
		d[i * t / 100] = 0;
		if (d[i])
			a.push_back(i);
	}
	num--;
	ans = num / a.size() * t;
	ans += a[num % a.size()];
	cout << ans << "\n";
	return 0;
}