#include <iostream>
#include <vector>
#include <string>
#include <algorithm>
#define MOD 1000000007
#define INF 1 << 30

using namespace std;
typedef long long ll;

int main(void) {
	int h, w, k, ans = 0, i, j, a;
	cin >> h >> w >> k;
	for (i = 0; i < h; i++) {
		for (j = 0; j < w; j++) {
			cin >> a;
			if ((i + j) <= k && ((i + j) & 1) == (k & 1))
				ans = max(ans, a);
		}
	}
	cout << ans << "\n";
	return 0;
}