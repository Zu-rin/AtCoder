#include <iostream>
#include <vector>
#include <string>
#include <algorithm>
#define MOD 1000000007
#define INF 1 << 30

using namespace std;
typedef long long ll;

int Parent(int n, vector<int> &p) {
	if (p[n] == n)
		return n;
	return p[n] = Parent(p[n], p);
}

int main(void) {
	ll num;
	int m, i, a, b;
	cin >> num >> m;
	vector<ll> ans(m), s(num + 1, 1);
	vector<int> fr(m), to(m), p(num + 1);
	for (i = 0; i < m; i++)
		cin >> fr[i] >> to[i];
	for(i = 0; i<= num; i++)
		p[i] = i;
	ans[m - 1] = num * (num - 1) >> 1;
	for (i = m - 1; i > 0; i--) {
		a = Parent(fr[i], p);
		b = Parent(to[i], p);
		if (a == b)
			ans[i - 1] = ans[i];
		else {
			p[max(a, b)] = min(a, b);
			ans[i - 1] = ans[i] - s[a] * s[b];
			s[min(a, b)] += s[max(a, b)];
		}
	}
	for (i = 0; i < m; i++)
		cout << ans[i] << "\n";
	return 0;
}