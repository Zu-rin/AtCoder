#include <iostream>
#include <vector>
#include <string>
#include <tuple>
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
	int num, m, i, j = 0, a, b, y, q;
	cin >> num >> m;
	vector<tuple<int, int, int>> d(m);
	vector<int> p(num + 1), s(num + 1, 1);
	for (i = 0; i < m; i++) {
		cin >> a >> b >> y;
		d[i] = make_tuple(-y, a, b);
	}
	sort(d.begin(), d.end());
	for (i = 1; i <= num; i++)
		p[i] = i;
	cin >> q;
	vector<tuple<int, int, int>> x(q);
	vector<int> ans(q);
	for (i = 0; i < q; i++) {
		cin >> a >> y;
		x[i] = make_tuple(-y, a, i);
	}
	sort(x.begin(), x.end());
	for (i = 0; i < q; i++) {
		for (; j < m; j++) {
			if (get<0>(d[j]) >= get<0>(x[i]))
				break;
			a = Parent(get<1>(d[j]), p);
			b = Parent(get<2>(d[j]), p);
			if (a != b) {
				if (s[a] < s[b]) {
					p[a] = b;
					s[b] += s[a];
				}
				else {
					p[b] = a;
					s[a] += s[b];
				}
			}
		}
		ans[get<2>(x[i])] = s[Parent(get<1>(x[i]), p)];
	}
	for (i = 0; i < q; i++)
		cout << ans[i] << "\n";
	return 0;
}