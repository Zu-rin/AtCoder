#include <iostream>
#include <vector>
#include <string>
#include <queue>
#include <algorithm>

using namespace std;
typedef long long ll;

int main(void) {
	int num, k, i;
	pair<ll, ll> p;
	ll a, b, ans = 0;
	priority_queue<pair<ll, ll>, vector<pair<ll, ll>>, greater<pair<ll, ll>>> que;
	cin >> num >> k;
	for (i = 0; i < num; i++) {
		scanf_s("%lld%lld", &a, &b);
		que.push(make_pair(a, b));
	}
	for (i = 0; i < k; i++) {
		p = que.top();
		que.pop();
		ans += p.first;
		p.first += p.second;
		que.push(p);
	}
	cout << ans << "\n";
	return 0;
}