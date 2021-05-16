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
	int num, i, p;
	ll ans = 0;
	cin >> num;
	vector<int> a(num), b(num);
	rep(i, num)
		cin >> a[i] >> b[i];
	sort(a.begin(), a.end());
	sort(b.begin(), b.end());
	p = ((num + 1) >> 1) - 1;
	if (num & 1) {
		ans = b[p] - a[p] + 1;
	}
	else {
		int l = a[p] + a[p + 1];
		int r = b[p] + b[p + 1];
		ans = r - l + 1;
	}
	cout << ans << "\n";
	return 0;
}