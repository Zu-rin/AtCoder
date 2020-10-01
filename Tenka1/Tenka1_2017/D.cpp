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

void Init(int k, vector<int> & d) {
	int a = 1;
	while (a <= k) {
		if (a & k) {
			d.push_back((k | (a - 1)) ^ a);
		}
		a <<= 1;
	}
	return;
}

int main(void) {
	int num, i, k;
	ll ans = 0;
	cin >> num >> k;
	vector<int> a(num), x = { k };
	vector<ll> b(num);
	rep(i, num) {
		cin >> a[i] >> b[i];
	}
	Init(k, x);
	for(auto t : x) {
		ll sum = 0;
		rep(i, num) {
			if ((t | a[i]) == t)
				sum += b[i];
		}
		chmax(ans, sum);
	}
	cout << ans << "\n";
	return 0;
}