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

void input(int num, vector<ll> &a) {
	int x, i;
	rep(i, num) {
		cin >> x;
		a[x % 46]++;
	}
}

int main(void) {
	int num, i, j;
	ll ans = 0;
	cin >> num;
	vector<ll> a(46, 0), b(46, 0), c(46, 0);
	input(num, a);
	input(num, b);
	input(num, c);
	rep(i, 46) {
		rep(j, 46) {
			ans += a[i] * b[j] * c[(92 - i - j) % 46];
		}
	}
	cout << ans << "\n";
	return 0;
}