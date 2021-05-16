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
	ll num, i, ok = 0, a, b, c, d, y, s, t;
	cin >> num >> a >> b >> c >> d;
	y = b - a;
	s = (num - 1) * c;
	t = (num - 1) * d;
	rep(i, num + 1) {
		if (s - (c + d) * i <= y && y <= t - (c + d) * i) {
			ok = 1;
			break;	
		}
	}
	if (ok)
		printf("YES\n");
	else
		printf("NO\n");
	return 0;
}