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
	int num, i, a, m = INF, ans = 0;
	cin >> num;
	rep(i, num) {
		cin >> a;
		chmin(m, a);
		if (a == m)
			ans++;
	}
	cout << ans << "\n";
	return 0;
}