#include <iostream>
#include <vector>
#include <string>
#include <algorithm>
#define MOD 1000000007
#define INF 1 << 30

using namespace std;
typedef long long ll;

int main(void) {
	int n, m, i, ans = 0;
	string s;
	cin >> n >> m;
	vector<int> a(26, 0), b(26, 0);
	cin >> s;
	for (i = 0; i < n; i++) {
		a[s[i] - 'A']++;
	}
	cin >> s;
	for (i = 0; i < m; i++) {
		b[s[i] - 'A']++;
	}
	for (i = 0; i < 26; i++) {
		if (a[i] == 0)
			continue;
		if (b[i] == 0) {
			ans = -1;
			break;
		}
		ans = max(ans, a[i] / b[i] + min(1, a[i] % b[i]));
	}
	cout << ans << "\n";
	return 0;
}