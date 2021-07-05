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
	int num, i;
	ll ans = 0, ma = 0;
	cin >> num;
	vector<ll> d(num), a(num);
	rep(i, num)
		cin >> d[i];
	a = d;
	rep(i, num - 1)
		a[i + 1] += a[i];
	a.push_back(0);
	rep(i, num) {
		chmax(ma, d[i]);
		cout << a[i] + ma * (i + 1) << "\n";
		a[i + 1] += a[i];
	}
	return 0;
}