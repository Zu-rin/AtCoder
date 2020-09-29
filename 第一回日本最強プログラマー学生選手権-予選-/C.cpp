#include <iostream>
#include <vector>
#include <algorithm>
#include <string>
#define MOD 1000000007

using namespace std;
typedef long long ll;

int main(void) {
	string s;
	int num, k = 1, i, j, l, r;
	ll ans = 1, ansr = 1;
	cin >> num >> s;
	vector<int> d(s.size() + 1, 0);
	l = 0;
	r = 0;
	for (i = 0; i < num * 2; i++) {
		if (s[i] == 'B') {
			if (d[i] & 1) {
				d[i + 1] = d[i] - 1;
				ans *= l - r;
				r++;
			}
			else {
				d[i + 1] = d[i] + 1;
				l++;
			}
		}
		else {
			if (d[i] & 1) {
				d[i + 1] = d[i] + 1;
				l++;
			}
			else {
				if (d[i] == 0) {
					ans = 0;
					break;
				}
				d[i + 1] = d[i] - 1;
				ans *= l - r;
				r++;
			}
		}
		if (l > num || r > num) {
			ans *= 0;
			break;
		}
		ans %= MOD;
	}
	for (i = 2; i <= num; i++) {
		ans *= i;
		ans %= MOD;
	}
	cout << ans << "\n";
	return 0;
}