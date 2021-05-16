#include <iostream>
#include <vector>
#include <string>
#include <algorithm>
#define rep(i, n) for(i = 0; i < (n); i++)
#define chmax(x, y) x = max(x, y)
#define chmin(x, y) x = min(x, y)
#define MOD 1000000007
#define INF 1 << 30

using namespace std;
typedef long long ll;
typedef pair<int, int> pp;

int main(void) {
	ll num, a, b;
	cin >> num >> a >> b;
	if ((a & 1) == (b & 1))
		cout << (b - a) / 2 << "\n";
	else
		cout << min(min(b - 1, a + (b - a) / 2), min(num - a, num - b + 1 + (b - a) / 2)) << "\n";
	return 0;
}