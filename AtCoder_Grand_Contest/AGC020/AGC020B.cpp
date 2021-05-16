#include <iostream>
#include <vector>
#include <string>
#include <algorithm>
#define MOD 1000000007
#define INF 1 << 30

using namespace std;
typedef long long ll;

int main(void) {
	int num, i;
	cin >> num;
	vector<ll> d(num), l(num + 1), r(num + 1);
	for (i = 0; i < num; i++)
		cin >> d[i];
	l[num] = 2;
	r[num] = 2;
	for (i = num - 1; i >= 0; i--) {
		if (l[i + 1] % d[i] == 0)
			l[i] = l[i + 1];
		else
			l[i] = d[i] * ((l[i + 1] / d[i]) + 1);
		r[i] = d[i] * ((r[i + 1] / d[i]) + 1) - 1;
		if (l[i] > r[i]) {
			printf("-1\n");
			return 0;
		}
	}
	printf("%lld %lld\n", l[0], r[0]);
	return 0;
}