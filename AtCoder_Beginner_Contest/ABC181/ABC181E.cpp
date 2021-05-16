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

// n�ȉ��̗v�f�̒��ōő�̓Y������Ԃ�
// n < min(d) : -1
// max(d) < n : d.size() - 1
int Binary_search(ll n, vector<ll> & d) {
	auto tag = upper_bound(d.begin(), d.end(), n);
	return distance(d.begin(), tag) - 1;
}

ll Solve(vector<ll>& d, vector<ll>& a, vector<ll>& b) {
	ll w, p, ans, bsum = *b.rbegin();
	cin >> w;
	p = Binary_search(w, d) + 1;
	if (p & 1)
		ans = a[p / 2] + bsum - b[p / 2] + w - d[p - 1];
	else
		ans = a[p / 2] + bsum - b[p / 2] + d[p] - w;
	return ans;
}

int main(void) {
	int num, m, i;
	ll ans = INF;
	cin >> num  >> m;
	vector<ll> d(num), a(1, 0), b(1, 0);
	rep(i, num)
		cin >> d[i];
	sort(d.begin(), d.end());
	rep(i, num - 1) {
		int sub = d[i + 1] - d[i];
		if (i & 1)
			b.push_back(*b.rbegin() + sub);
		else
			a.push_back(*a.rbegin() + sub);
	}
	rep(i, m)
		chmin(ans, Solve(d, a, b));
	cout << ans << "\n";
	return 0;
}