#include <iostream>
#include <vector>
#include <string>
#include <cmath>
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
	int num, i;
	double p, x, ans, buf;
	cin >> p;
	x = -1.5 * log2(3.0 / (2.0 * p * log(2.0)));
	if (x <= 0)
		x = 0;
	ans = x + p * powl(2.0, -2.0 * x / 3.0);
	printf("%.10lf\n", ans);
	return 0;
}