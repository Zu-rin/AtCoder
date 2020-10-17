#include <iostream>
#include <vector>
#include <string>
#include <list>
#include <queue>
#include <cmath>
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

void F1(vector<ll> & d) {
	ll ans = 0;
	int i;
	rep(i, d.size())
		ans += abs(d[i]);
	cout << ans << "\n";
	return;
}

void F2(vector<ll>& d) {
	int i;
	ll sum = 0;
	rep(i, d.size()) {
		sum += d[i] * d[i];
	}
	double ans = sqrt((double)sum);
	printf("%.11lf\n", ans);
	return;
}

void F3(vector<ll>& d) {
	int i;
	ll ans = 0;
	rep(i, d.size()) {
		chmax(ans, abs(d[i]));
	}
	cout << ans << "\n";
	return;
}

int main(void) {
	int num, i;
	cin >> num;
	vector<ll> d(num);
	rep(i, num)
		cin >> d[i];
	F1(d);
	F2(d);
	F3(d);
	return 0;
}