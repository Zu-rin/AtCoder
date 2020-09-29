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
	ll x = 7, i, n;
	cin >> n;
	rep(i, n) {
		if (x % n == 0)
			break;
		x %= n;
		x = 10 * x + 7;
	}
	if (i >= n)
		printf("-1\n");
	else
		cout << i + 1 << "\n";
	return 0;
}