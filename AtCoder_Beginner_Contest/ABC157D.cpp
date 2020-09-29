#include <iostream>
#include <vector>
#include <string>
#include <map>
#include <algorithm>
#define rep(i, n) for(i = 0; i < (n); i++)
#define chmax(x, y) x = max(x, y)
#define chmin(x, y) x = min(x, y)
#define MOD 1000000007
#define INF 1 << 30

using namespace std;
typedef long long ll;
typedef pair<int, int> pp;

int Parent(int n, vector<int> & p) {
	if (p[n] == n)
		return n;
	return p[n] = Parent(p[n], p);
}

int main(void) {
	int num, i, m, k, a, b;
	cin >> num >> m >> k;
	vector<int> p(num + 1), s(num + 1, 1);
	vector<map<int, int>> x(num + 1);
	rep(i, num + 1) {
		p[i] = i;
	}
	rep(i, m) {
		cin >> a >> b;
		x[a][b]++;
		x[b][a]++;
		a = Parent(a, p);
		b = Parent(b, p);
		if (a != b) {
			p[b] = a;
			s[a] += s[b];
		}
	}
	rep(i, k) {
		cin >> a >> b;
		if (Parent(a, p) == Parent(b, p)) {
			x[a][b]++;
			x[b][a]++;
		}
	}
	for (i = 1; i <= num; i++) {
		a = Parent(i, p);
		cout << s[a] - x[i].size() - 1 << " ";
	}
	printf("\n");
	return 0;
}