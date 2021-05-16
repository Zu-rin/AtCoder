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

int s;

int Cycle(int & a, int & p, vector<int> & d) {
	int n = s, ans = 1;
	vector<int> m(d.size(), 0);
	m[s] = 1;
	while (true) {
		ans++;
		n = d[n];
		if (m[n])
			break;
		m[n] = ans;
	}
	a = m[n] - 1;
	p = n;
	return ans - m[n];
}

int Solve(ll c, ll a, int p, string& t, vector<int>& d) {
	ll i, n = 0;
	for (int i = 0; i < t.size(); i++) {
		n *= 10;
		n += t[i] - '0';
		n %= c;
	}
	n -= a;
	while (n < 0)
		n += c;
	rep(i, n)
		p = d[p];
	return p;
}

int main(void) {
	int num, i, a, p, c;
	string k;
	cin >> num >> s >> k;
	vector<int> d(num + 1);
	for(i = 1; i <= num; i++)
		cin >> d[i];
	if (k.size() <= 6) {
		ll x = stoi(k);
		rep(i, x)
			s = d[s];
		cout << s << "\n";
		return 0;
	}
	c = Cycle(a, p, d);
	cout << Solve(c, a, p, k, d) << "\n";
	return 0;
}