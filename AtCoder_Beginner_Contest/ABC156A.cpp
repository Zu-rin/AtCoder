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
	int num, r, ans;
	cin >> num >> r;
	if (num >= 10)
		ans = r;
	else {
		ans = r + 100 * (10 - num);
	}
	cout << ans << "\n";
	return 0;
}