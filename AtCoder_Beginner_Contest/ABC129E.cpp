#include <iostream>
#include <string>
#include <vector>
#define MOD 1000000007
using namespace std;
typedef long long ll;

int main(void) {
	string s;
	cin >> s;
	vector<ll> dp0(s.size(), 0), dp1(s.size(), 0); //0: L–¢–žŠm’è
	int i;
	dp0[0] = 1;
	dp1[0] = 2;
	for (i = 1; i < s.size(); i++) {
		dp0[i] = (dp0[i - 1] * 3) % MOD;
		if (s[i] == '0') {
			dp1[i] = dp1[i - 1];
		}
		else {
			(dp0[i] += dp1[i - 1]) %= MOD;
			dp1[i] = (dp1[i - 1] << 1) % MOD;
		}
	}
	cout << (dp0[s.size() - 1] + dp1[s.size() - 1]) % MOD << "\n";
	return 0;
}