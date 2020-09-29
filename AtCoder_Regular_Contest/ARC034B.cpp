#include <iostream>
#include <vector>
#include <string>
#include <queue>
#include <algorithm>
#define MOD 1000000007
#define INF 1 << 30

using namespace std;
typedef long long ll;

ll func(ll n) {
	if (n < 0)
		return 0;
	ll ans = 0;
	while (n > 0) {
		ans += n % 10;
		n /= 10;
	}
	return ans;
}

int main(void) {
	ll num, i;
	priority_queue<ll, vector<ll>, greater<ll>> ans;
	cin >> num;
	for (i = 1; i <= 162; i++) {
		if (i == func(num - i))
			ans.push(num - i);
	}
	cout << ans.size() << "\n";
	while (!ans.empty()) {
		cout << ans.top() << "\n";
		ans.pop();
	}
	return 0;
}