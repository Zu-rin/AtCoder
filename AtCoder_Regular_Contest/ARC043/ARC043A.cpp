#include <iostream>
#include <vector>
#include <string>
#include <algorithm>
#define MOD 1000000007
#define INF 1 << 30

using namespace std;
typedef long long ll;

int main(void) {
	ll num, i, a, b, ma = 0, mi = INF, sum = 0, x;
	double p, q;
	cin >> num >> a >> b;
	for (i = 0; i < num; i++) {
		cin >> x;
		ma = max(ma, x);
		mi = min(mi, x);
		sum += x;
	}
	if (ma == mi) {
		printf("-1\n");
		return 0;
	}
	p = (double)b / (double)(ma - mi);
	q = (double)sum * p / (double)num;
	q = (double)a - q;
	printf("%.9lf %.9lf\n", p, q);
	return 0;
}