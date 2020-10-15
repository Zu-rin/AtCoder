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
	int num, i, ok = 1;
	ll k = 1, a = 1;
	cin >> num;
	vector<ll> d(num);
	rep(i, 18)
		k *= 10ll;
	rep(i, num)
		cin >> d[i];
	sort(d.begin(), d.end());
	rep(i, num) {
		if (!a)
			break;
		if (d[i] > k / a) {
			ok = 0;
			break;
		}
		a *= d[i];
	}
	if (ok)
		cout << a << "\n";
	else
		printf("-1\n");
	return 0;
}