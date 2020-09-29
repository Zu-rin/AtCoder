#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;
typedef long long ll;

ll Conbi(int a, int b) {
	if (b > a)
		return 0;
	b = min(b, a - b);
	if (b == 0)
		return 1;
	ll ans = 1;
	for (int i = 1; i <= b; i++, a--) {
		ans *= a;
		ans /= i;
	}
	return ans;
}

int main(void) {
	int num, l, r, i, m = 0, s;
	ll ans = 0;
	double ave = 0.0;
	cin >> num >> l >> r;
	vector<ll> d(num);
	for (i = 0; i < num; i++)
		scanf_s("%lld", &d[i]);
	sort(d.begin(), d.end(), greater<ll>());
	for (i = 0; i < l; i++) {
		ave += (double)d[i];
		if (d[i] == d[l - 1])
			m++;
	}
	for (s = m; i < num; i++) {
		if (d[i] == d[l - 1])
			s++;
	}
	if (d[0] != d[l - 1])
		r = l;
	for (i = 0; i <= r - l; i++)
		ans += Conbi(s, m + i);
	ave /= (double)l;
	printf("%.9lf\n%lld\n", ave, ans);
	return 0;
}