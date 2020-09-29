#include <iostream>
#include <vector>
#include <string>
#include <algorithm>
#define MOD 1000000007
#define INF 1 << 30

using namespace std;
typedef long long ll;

int main(void) {
	int num, k, i, j, ans = 0, ok;
	string s, t = "spr";
	vector<int> a(3);
	cin >> num >> k >> a[0] >> a[1] >> a[2] >> s;
	vector<vector<int>> dp(num, vector<int>(3, 0));
	for (i = 0; i < k; i++) {
		for (j = i; j < num; j += k) {
			if (j < k || s[j] != s[j - k] || ok) {
				ans += a[t.find(s[j])];
				ok = false;
			}
			else
				ok = true;
		}
	}
	cout << ans << "\n";
	return 0;
}