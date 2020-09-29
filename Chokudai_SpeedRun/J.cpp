#include <iostream>
#include <vector>
#include <string>
#include <list>
#include <queue>
#include <set>
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

void make_div(int n, set<int> & st) {
	for (ll i = 1; i * i <= n; i++) {
		if (n % i == 0) {
			st.insert(i);
			st.insert(n / i);
		}
	}
	return;
}

int Judge(int n, vector<int>& a, vector<int> &b) {
	int i;
	rep(i, a.size()) {
		if (a[i] % n && b[i] % n)
			return 0;
	}
	return 1;
}

int main(void) {
	int num, i, ans = 0;
	set<int> st;
	cin >> num;
	vector<int> a(num), b(num);
	rep(i, num) {
		cin >> a[i] >> b[i];
	}
	make_div(a[0], st);
	make_div(b[0], st);
	for (auto it = st.begin(); it != st.end(); it++) {
		if (Judge(*it, a, b))
			chmax(ans, *it);
	}
	cout << ans << "\n";
	return 0;
}