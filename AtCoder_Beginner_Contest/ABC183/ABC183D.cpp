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
	int i, ok = 1;
	ll num, k, a, b, q;
	cin >> num >> k;
	vector<ll> d(200001, 0);
	rep(i, num) {
		cin >> a >> b >> q;
		d[a] += q;
		d[b] -= q;
	}
	rep(i, d.size() - 1) {
		d[i + 1] += d[i];
		if (d[i] > k) {
			ok = 0;
			break;
		}
	}
	if (ok)
		printf("Yes\n");
	else
		printf("No\n");
	return 0;
}