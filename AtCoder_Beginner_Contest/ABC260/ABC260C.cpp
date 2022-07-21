#include <iostream>
#include <vector>
#include <string>
#include <list>
#include <set>
#include <map>
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
	ll num, x, y;
	cin >> num >> x >> y;
	vector<ll> a(11, 0), b(11, 0);
	a[num] = 1;
	for (int i = 10; i > 1; i--) {
		a[i - 1] += a[i];
		b[i] += x * a[i];
		a[i - 1] += b[i];
		b[i - 1] += y * b[i];
	}
	cout << b[1] << "\n";
	return 0;
}