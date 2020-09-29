#include <iostream>
#include <vector>
#include <string>
#include <algorithm>
#define MOD 1000000007
#define INF 1 << 30

using namespace std;
typedef long long ll;

int main(void) {
	int num, i, ans = 0;
	string s;
	cin >> s;
	for (i = 0; i < s.size(); i++) {
		if (s[i] >= '0' && s[i] <= '9') {
			ans *= 10;
			ans += s[i] - '0';
		}
	}
	cout << ans << "\n";
	return 0;
}