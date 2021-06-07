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

ll Search(int n, vector<ll> &d) {
	if (d[n])
		return d[n];
	ll ans = 0;
	for (int i = 1; i <= min(9, n); i++) {
		ans += Search(n - i, d);
	}
	return d[n] = (ans % MOD);
}

int main(void) {
	int n;
	cin >> n;
	if (n % 9) {
		printf("0\n");
		return 0;
	}
	vector<ll> d(n + 1, 0);
	d[0] = 1;
	cout << Search(n, d) << "\n";
	return 0;
}