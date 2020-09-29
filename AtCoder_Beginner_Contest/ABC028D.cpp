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
	double num, k, ans, n3;
	cin >> num >> k;
	n3 = num * num * num;
	ans = 6.0 * (k - 1) * (num - k) / n3;
	ans += 3.0 * (num - k) / n3;
	ans += 3.0 * (k - 1) / n3;
	ans += 1.0 / n3;
	printf("%.15lf\n", ans);
	return 0;
}