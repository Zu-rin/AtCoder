#include <iostream>
#include <vector>
#include <string>
#include <list>
#include <queue>
#include <algorithm>
#define rep(i, n) for(i = 0; i < (n); i++)
#define chmax(x, y) x = max(x, y)
#define chmin(x, y) x = min(x, y)
#define MOD 1000000007
#define PI 3.14159265358979323846
#define INF 1 << 30

using namespace std;
typedef long long ll;
typedef pair<int, int> pp;

ll Sum(int s, int e, vector<ll> & x, char d) {
	ll ans = 0, tag;
	if (d == 'L') {
		tag = x[s] + 1;
		for (int i = s + 1; i <= e; i++) {
			ans += x[i] - tag;
			tag++;
		}
	}
	else {
		tag = x[e] - 1;
		for (int i = e - 1; i >= s; i--) {
			ans += tag - x[i];
			tag--;
		}
	}
	return ans;
}

void Input(vector<ll> &x, vector<char> &d) {
	int i, num;
	ll a, l;
	char c;
	cin >> num >> l;
	d.push_back('R');
	d.push_back('L');
	x.push_back(-1);
	x.push_back(0);
	rep(i, num) {
		cin >> a >> c;
		x.push_back(a);
		d.push_back(c);
	}
	d.push_back('R');
	d.push_back('L');
	x.push_back(l + 1);
	x.push_back(l + 2);
	return;
}

int main(void) {
	int i, s = 0, e = 0, p;
	ll ans = 0;
	vector<char> d;
	vector<ll> x;
	Input(x, d);
	rep(i, x.size() - 1) {
		if (d[i] == 'L' && d[i + 1] == 'L') {
			ans += x[i + 1] - x[i] - 1;
			x[i + 1] = x[i] + 1;
		}
	}
	for (i = x.size() - 1; i > 0; i--) {
		if (d[i] == 'R' && d[i - 1] == 'R') {
			ans += x[i] - x[i - 1] - 1;
			x[i - 1] = x[i] - 1;
		}
	}
	while (s < d.size()) {
		while (d[e] == 'R')
			e++;
		p = e;
		while (e < d.size() && d[e] == 'L')
			e++;
		ans += max(Sum(s, p, x, d[s]), Sum(p - 1, e - 1, x, d[p]));
		s = e;
	}
	cout << ans << "\n";
	return 0;
}