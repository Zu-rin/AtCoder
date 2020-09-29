#include <iostream>
#include <vector>
#include <string>
#include <algorithm>
#define MOD 1000000007
#define INF 1 << 30

using namespace std;
typedef long long ll;

int main(void) {
	int num, k, i, a, b, ans;
	string s;
	cin >> num >> k >> s;
	for (a = 0; a < s.size(); a++) {
		if (s[a] == '.')
			break;
	}
	for (b = s.size() - 1; b >= 0; b--) {
		if (s[b] == '.')
			break;
	}
	if (b < a) {
		printf("0\n");
		return 0;
	}
	ans = max(0, b - k + 1);
	for (i = a; i <= b; i++) {
		if (s[i] == '.') {
			ans++;
			i += k - 1;
		}
	}
	cout << ans << "\n";
	return 0;
}