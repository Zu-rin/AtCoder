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
	int num, i, a, b, ans;
	cin >> a >> b;
	rep(ans, 2000) {
		if (ans * 8 / 100 == a && ans / 10 == b)
			break;
	}
	if (ans == 2000)
		printf("-1\n");
	else
		cout << ans << "\n";
	return 0;
}