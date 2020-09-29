#include <iostream>
#include <vector>
#include <string>
#include <algorithm>
#define MOD 1000000007
#define INF 1 << 30

using namespace std;
typedef long long ll;

int main(void) {
	int num, k, i, j;
	ll ans = 0, buf, a = 0, x;
	cin >> num >> k;
	vector<pair<int, int>> d(num);
	vector<int> s(num + 1, 0);
	for (i = 0; i < num; i++)
		cin >> d[i].second >> d[i].first;
	sort(d.begin(), d.end(), greater<pair<int, int>>());
	for (i = 0; i < k; i++) {
		ans += d[i].first;
		if (s[d[i].second] == 0)
			a++;
		s[d[i].second]++;
	}
	buf = ans;
	ans += a * a;
	for (i = k, j = k - 1 ; i < num; i++) {
		if (s[d[i].second] == 0) {
			for (; j >= 0; j--) {
				if (s[d[j].second] > 1)
					break;
			}
			if (j < 0)
				break;
			buf += d[i].first - d[j].first;
			a++;
			ans = max(ans, buf + a * a);
			s[d[i].second]++;
			s[d[j].second]--;
			j--;
		}
	}
	cout << ans << "\n";
	return 0;
}